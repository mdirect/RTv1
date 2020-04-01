/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 14:19:22 by mdirect           #+#    #+#             */
/*   Updated: 2020/04/01 11:56:23 by estel            ###   ########.fr       */
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

__uint32_t		make_color(t_param_window *p, int i, t_point v)
{
	double	intens;
	t_point l;
	t_point r;
	double 	scal;
	double 	scal_r;
	int 	j;

	intens = 0;
	l = (t_point){0.0, 0.0, 0.0};
	j = -1;
	while (++j < LIGHT_C)
	{
		if (p->scene.light[j].type == 0)
			intens += p->scene.light[j].intens;
		else if (p->scene.light[j].type == 1)
			l = vector(p->scene.light[j].c, p->scene.sph[i].p);
		else
			l = p->scene.light[j].c;
		scal = scalar(l, p->scene.sph[i].n);

		if (scal > 0)
			intens += p->scene.light[j].intens * scal /
					  (modul(p->scene.sph[i].n) * modul(l));

		if (p->scene.sph[i].specular != -1)
		{
			r = vector(multi(2.0 * scal, p->scene.sph[i].n), l);
			scal_r = scalar(v, r);
			if (scal_r > 0)
				intens += p->scene.light[j].intens * pow(scal_r / (modul(r) * modul(v)), p->scene.sph[i].specular);
		}
	}
	return (k_color(intens, p->scene.sph[i].color));
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
	return (make_color(p, cls_sph, (t_point) {-x, -y, -1}));
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
