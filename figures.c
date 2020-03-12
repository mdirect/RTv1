/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figures.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 13:02:52 by mdirect           #+#    #+#             */
/*   Updated: 2020/02/14 13:03:12 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_light		make_light(int type, double intens, t_point c)
{
	t_light light;

	light.type = type;
	light.intens = intens;
	light.c.x = c.x;
	light.c.y = c.y;
	light.c.z = c.z;
	return (light);
}

t_sphere	make_sphere(t_point centre, double radius, __uint32_t color)
{
	t_sphere sphere;

	sphere.c.x = centre.x;
	sphere.c.y = centre.y;
	sphere.c.z = centre.z;
	sphere.r = radius;
	sphere.color = color;
	return (sphere);
}
