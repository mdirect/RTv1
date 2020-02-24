/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 14:19:22 by mdirect           #+#    #+#             */
/*   Updated: 2020/02/24 13:49:32 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			create_windows(t_param_window *p)
{
	int				endian;

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

void			draw(t_param_window *p, t_scene *scene)
{
	int		i;
	int		j;
	double	x;
	double	y;

	j = 0;
	while (j < WIN_Y)
	{
		y = (WIN_Y / 2 - (double)j) * (1.0 / WIN_Y);
		i = 0;
		while (i < WIN_X)
		{
			x = (-WIN_X / 2 + (double)i) * (1.0 / WIN_X);
			if (hit_sphere(scene, (t_point){x, y, 1}))
				p->img_data[j * WIN_X + i] = scene->sph.color;
			else
				p->img_data[j * WIN_X + i] = scene->bg_color;
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(p->mlx, p->window, p->img, 0, 0);
}
