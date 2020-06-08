/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figures.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 13:02:52 by mdirect           #+#    #+#             */
/*   Updated: 2020/06/08 14:01:23 by estel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_light		make_light(int type, double intens, t_point c)
{
	t_light light;

	ft_bzero(&light, sizeof(light));
	light.type = type;
	light.intens = intens;
	light.c = c;
	return (light);
}

t_object	make_sphere(t_point centre, double radius, t_point color,
			double specular, double mirror)
{
	t_object sphere;

	ft_bzero(&sphere, sizeof(sphere));
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

t_object	make_cone(t_point centre, t_point line, double angle,
			t_point color, double specular, double mirror)
{
	t_object cone;

	ft_bzero(&cone, sizeof(cone));
	cone.type = 3;
	cone.c = centre;
	cone.l = multi(1 / modul(line), line);
	cone.angle = angle;
	cone.color = color;
	cone.specular = specular;
	cone.mirror = mirror;
	return (cone);
}

t_object	make_plane(t_point c, t_point line, t_point color,
			double specular, double mirror)
{
	t_object plane;

	ft_bzero(&plane, sizeof(plane));
	plane.c = c;
	plane.type = 4;
	plane.l = multi(1 / modul(line), line);
	plane.color = color;
	plane.specular = specular;
	plane.mirror = mirror;
	return (plane);
}
