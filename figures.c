/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figures.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 13:02:52 by mdirect           #+#    #+#             */
/*   Updated: 2020/04/12 11:19:23 by estel            ###   ########.fr       */
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

t_object	make_sphere(t_point centre, double radius, t_point color,
			double specular, double mirror)
{
	t_object sphere;

	sphere.type = 1;
	sphere.c.x = centre.x;
	sphere.c.y = centre.y;
	sphere.c.z = centre.z;
	sphere.r = radius;
	sphere.color.x = color.x;
	sphere.color.y = color.y;
	sphere.color.z = color.z;
	sphere.specular = specular;
	sphere.mirror = mirror;
	return (sphere);
}

t_object	make_cylinder(t_point centre, double radius, t_point line, t_point color, double specular, double mirror)
{
	t_object cylinder;

	cylinder.type = 2;
	cylinder.c.x = centre.x;
	cylinder.c.y = centre.y;
	cylinder.c.z = centre.z;
	cylinder.r = radius;
	cylinder.l = line;
	cylinder.color.x = color.x;
	cylinder.color.y = color.y;
	cylinder.color.z = color.z;
	cylinder.specular = specular;
	cylinder.mirror = mirror;
	return (cylinder);
}
