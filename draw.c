/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 14:19:22 by mdirect           #+#    #+#             */
/*   Updated: 2020/02/13 14:19:22 by mdirect          ###   ########.fr       */
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

void 	draw(t_param_window *p)
{

}
