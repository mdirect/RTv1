/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 14:19:22 by mdirect           #+#    #+#             */
/*   Updated: 2020/02/23 16:12:47 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			create_windows(t_param_window *p)
{
	int				bpp;
	int				endian;

	p->mlx = mlx_init();
	p->window = mlx_new_window(p->mlx, WIN_X, WIN_Y, "RTv1");
	p->img = mlx_new_image(p->mlx, WIN_X, WIN_Y);
	bpp = 32;
	endian = 0;
	p->win_x = WIN_X;
	p->img_data = (int *)mlx_get_data_addr(p->img, &bpp, &(p->win_x), &endian);
	mlx_put_image_to_window(p->mlx, p->window, p->img, 0, 0);
}

double 			hit_sphere(t_scene *scene, t_point d)
{
	double t1, t2;
	double disc;
	double a, b, c;

	a = scalar(d, d);
	b = scalar(scene->sph.c, d);
	c = scalar(scene->sph.c, scene->sph.c) - (scene->sph.r * scene->sph.r);
	disc = b * b - a * c;
	if (disc < 0)
		return (0);
	t1 = (-b + sqrt(disc)) / a;
	t2 = (-b - sqrt(disc)) / a;
	if (t1 == t2 && t1 > 1)
		return (t1);
	else
	{
		if (t1 < t2)
			if (t1 > 1)
				return (t1);
			if (t2 > 1)
				return (t2);
		if (t1 > t2)
			if (t2 > 1)
				return (t2);
			if (t1 > 1)
				return (t1);
	}
	return (0);
}

void 			draw(t_param_window *p, t_scene *scene)
{
	int i, j;
	double x, y;

	i = 0;
	while (i < WIN_X)
	{
		x = -0.5 + (double)i / WIN_X;
		j = 0;
		while (j < WIN_Y)
		{
			y = 0.5 - (double)j / WIN_Y;
			if ((hit_sphere(scene, (t_point){x, y, 1})))
				mlx_pixel_put(p->mlx, p->window, i, j, scene->sph.color);
			else
				mlx_pixel_put(p->mlx, p->window, i, j, scene->bg_color);

//			if ((x*x + y*y) <=  (scene->sph.r * scene->sph.r))
//				mlx_pixel_put(p->mlx, p->window, i, j, scene->sph.color);
//			else
//				mlx_pixel_put(p->mlx, p->window, i, j, scene->bg_color);
			j++;
		}
		i++;
	}
}
