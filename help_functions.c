/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 13:37:20 by mdirect           #+#    #+#             */
/*   Updated: 2020/02/24 13:16:47 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

__uint32_t		k_color(double k, __uint32_t color)
{
	unsigned int r;
	unsigned int g;
	unsigned int b;

	if (k <= 0)
		return (0);
	r = color >> (unsigned)16;
	g = ((color  << (unsigned)16)) >> (unsigned)24;
	b = ((color  << (unsigned)24)) >> (unsigned)24;
	r = ((k * r) > 255) ? 255 : (k * r);
	g = ((k * g) > 255) ? 255 : (k * g);
	b = ((k * b) > 255) ? 255 : (k * b);
	color = (r << (unsigned)16) | (g << (unsigned)8) | b;
	return (color);
}

__uint32_t		add_color(__uint32_t color1, __uint32_t color2)
{
	unsigned int r;
	unsigned int g;
	unsigned int b;

	r = (color1 >> (unsigned)16) | (color2 >> (unsigned)16);
	g = (((color1  << (unsigned)16)) >> (unsigned)24) |
		(((color2  << (unsigned)16)) >> (unsigned)24);
	b = (((color1  << (unsigned)24)) >> (unsigned)24) |
		(((color2  << (unsigned)24)) >> (unsigned)24);
	r = (r > 255) ? 255 : r;
	g = (g > 255) ? 255 : g;
	b = (b > 255) ? 255 : b;
	return ((r << (unsigned)16) | (g << (unsigned)8) | b)  ;
}

/*
 * The quadratic formula for the roots of the quadratic equation use D/4
 */

double 			quadr_eq_solve(double a, double b, double c)
{
	double disc;
	double t1;
	double t2;

	disc = b * b - a * c;
	if (disc < 0)
		return (0);
	t1 = (-b + sqrt(disc)) / a;
	t2 = (-b - sqrt(disc)) / a;
	if (t1 == t2 && t1 > 1)
		return (t1);
	if (((t1 > t2 && t2 <= 1) || t1 < t2) && t1 > 1)
		return (t1);
	if (((t1 < t2 && t1 <= 1) || t1 > t2) && t2 > 1)
		return (t2);
	return (1);
}

int			ft_usage(void)
{
	write(1, "usage: ./rt input_rt\n", 21);
	return (0);
}
