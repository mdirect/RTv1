/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 14:19:22 by mdirect           #+#    #+#             */
/*   Updated: 2020/02/13 15:05:55 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	create_windows(t_param_window *p)
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

void 	draw(t_param_window *p, t_scene *scene)
{
	int i, j;
	int x, y;

	i = 0;
	while (i < WIN_X)
	{
		x = (-WIN_X / 2 + i) / WIN_X;
		j = 0;
		while (j < WIN_Y)
		{
			y = (-WIN_Y / 2 + i) / WIN_Y;
			if ((x*x + y*y) <=  (scene->sph.r * scene->sph.r))
				mlx_pixel_put(p->mlx, p->window, i, j, 0xffffff);
			j++;
		}
		i++;
	}
}
