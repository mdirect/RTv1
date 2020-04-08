/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 13:37:20 by mdirect           #+#    #+#             */
/*   Updated: 2020/04/08 12:21:10 by estel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

__uint32_t	check_color(t_point c)
{
	__uint32_t color;
	unsigned int r, g, b;

	r = fmin(255, fmax(0, c.x));
	g = fmin(255, fmax(0, c.y));
	b = fmin(255, fmax(0, c.z));
	color = (r << (unsigned)16) | (g << (unsigned)8) | b;
	return (color);
}

/*
** The quadratic formula for the roots of the quadratic equation use D/4
*/

void		quadr_eq_solve(double a, double b, double c, double *t1, double *t2)
{
	double disc;

	disc = b * b - a * c;
	if (disc < 0)
	{
		*t1 = INFINITY;
		*t2 = INFINITY;
	}
	else
	{
		*t1 = (-b + sqrt(disc)) / a;
		*t2 = (-b - sqrt(disc)) / a;
	}
}

int			ft_usage(void)
{
	write(1, "usage: ./rt input_rt\n", 21);
	return (0);
}

void		create_windows(t_param_window *p)
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
