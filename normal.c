/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 12:41:49 by mdirect           #+#    #+#             */
/*   Updated: 2020/04/13 10:33:52 by estel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	normal(t_object *obj, t_point o, t_point d)
{
	if (obj->type == 1)
		normal_sphere(obj);
	if (obj->type == 2)
		normal_cylinder(obj, o, d);
	if (obj->type == 3)
		normal_cone(obj, o, d);
}

void	normal_sphere(t_object *sph)
{
	sph->n = vector(sph->c, sph->p);
	sph->n = multi(1.0 / modul(sph->n), sph->n);
}

void	normal_cylinder(t_object *cyl, t_point o, t_point d)
{
	double m;

	m = cyl->t[0] * scalar(d, cyl->l) + scalar(vector(cyl->c, o), cyl->l);
	cyl->n = vector(multi(m, cyl->l), vector(cyl->c, cyl->p));
	cyl->n = multi(1.0 / modul(cyl->n), cyl->n);
}

void	normal_cone(t_object *cone, t_point o, t_point d)
{
	double m;

	m = cone->t[0] * scalar(d, cone->l) + scalar(vector(cone->c, o), cone->l);
	m *= (1 + pow(tan(cone->angle), 2));
	cone->n = vector(multi(m, cone->l), vector(cone->c, cone->p));
	cone->n = multi(1.0 / modul(cone->n), cone->n);
}
