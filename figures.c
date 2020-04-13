/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figures.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 13:02:52 by mdirect           #+#    #+#             */
/*   Updated: 2020/04/13 10:17:41 by estel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_light		make_light(int type, double intens, t_point c)
{
	t_light light;

	light.type = type;
	light.intens = intens;
	light.c = c;
	return (light);
}

t_object	make_sphere(t_point centre, double radius, t_point color,
			double specular, double mirror)
{
	t_object sphere;

	sphere.type = 1;
	sphere.c = centre;
	sphere.r = radius;
	sphere.color = color;
	sphere.specular = specular;
	sphere.mirror = mirror;
	return (sphere);
}

t_object	make_cylinder(t_point centre, double radius, t_point line,
			t_point color, double specular, double mirror)
{
	t_object cylinder;

	cylinder.type = 2;
	cylinder.c = centre;
	cylinder.r = radius;
	cylinder.l = multi(1 / modul(line), line);
	cylinder.color = color;
	cylinder.specular = specular;
	cylinder.mirror = mirror;
	return (cylinder);
}

t_object	make_cone(t_point centre, t_point line, double angle, t_point color, double specular, double mirror)
{
	t_object cone;

	cone.type = 3;
	cone.c = centre;
	cone.l = multi(1 / modul(line), line);
	cone.angle = angle;
	cone.color = color;
	cone.specular = specular;
	cone.mirror = mirror;
	return (cone);
}
