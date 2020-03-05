/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 14:19:22 by mdirect           #+#    #+#             */
/*   Updated: 2020/03/04 13:15:03 by estel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			create_windows(t_param_window *p)
{
	int		endian;

	p->mlx = mlx_init();
	p->window = mlx_new_window(p->mlx, WIN_X, WIN_Y, "RTv1");
	p->img = mlx_new_image(p->mlx, WIN_X, WIN_Y);
	p->bpp = 32;
	endian = 0;
	p->win_x = WIN_X;
	p->img_data = (int *)mlx_get_data_addr(p->img, &p->bpp,
			&(p->win_x), &endian);
	mlx_put_image_to_window(p->mlx, p->window, p->img, 0, 0);
}

__uint32_t		make_color(t_param_window *p, int i)
{
	t_point	l;

	l = vector(p->scene.light, p->scene.sph[i].p);
	l = multi(1.0 / modul(l), l);
	if (scalar(l, p->scene.sph[i].n) > 0)
		return (add_color(k_color(scalar(l, p->scene.sph[i].n),
				0xFFFFFF), p->scene.sph[i].color));
	else
		return (k_color(sqrt(1 - pow(scalar(l, p->scene.sph[i].n), 2)),
				p->scene.sph[i].color));
}

__uint32_t		rt(t_param_window *p, double x, double y)
{
	int		i;
	double	cls_t;
	int		cls_sph;

	cls_t = 999999;
	cls_sph = -1;
	i = -1;
	while (++i < SPH_C)
		if (hit_sphere(&p->scene, (t_point) {x, y, 1}, i))
			if (p->scene.sph[i].t < cls_t)
			{
				cls_t = p->scene.sph[i].t;
				cls_sph = i;
			}
	if (cls_sph == -1)
		return (p->scene.bg_color);
	return (make_color(p, cls_sph));
}

void			draw(t_param_window *p)
{
	int		i;
	int		j;
	double	x;
	double	y;

	j = -1;
	while (++j < WIN_Y)
	{
		i = -1;
		while (++i < WIN_X)
		{
			x = (-WIN_X / 2 + (double)i) * (1.0 / WIN_X);
			y = (WIN_Y / 2 - (double)j) * (1.0 / WIN_Y);
			p->img_data[j * WIN_X + i] = rt(p, x, y);
		}
	}
	mlx_put_image_to_window(p->mlx, p->window, p->img, 0, 0);
}
