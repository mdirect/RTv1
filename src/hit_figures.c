/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_figures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 11:32:33 by mdirect           #+#    #+#             */
/*   Updated: 2020/06/25 09:18:58 by estel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		hit_figures(t_object *obj, t_point o, t_point d)
{
	if (obj->type == 1)
		hit_sphere(obj, o, d);
	if (obj->type == 2)
		hit_cylinder(obj, o, d);
	if (obj->type == 3)
		hit_cone(obj, o, d);
	if (obj->type == 4)
		hit_plane(obj, o, d);
}

void		hit_sphere(t_object *sph, t_point o, t_point d)
{
	double a;
	double b;
	double c;

	a = scalar(d, d);
	b = scalar(vector(sph->c, o), d);
	c = scalar(vector(sph->c, o), vector(sph->c, o)) - (sph->r * sph->r);
	quadr_eq_solve(a, b, c, &sph->root);
}

void		hit_cylinder(t_object *cyl, t_point o, t_point d)
{
	double	a;
	double	b;
	double	c;

	a = scalar(d, d) - pow(scalar(d, cyl->l), 2);
	b = scalar(vector(cyl->c, o), d) - scalar(d, cyl->l) *
			scalar(vector(cyl->c, o), cyl->l);
	c = scalar(vector(cyl->c, o), vector(cyl->c, o)) -
			pow(scalar(vector(cyl->c, o), cyl->l), 2) - (cyl->r * cyl->r);
	quadr_eq_solve(a, b, c, &cyl->root);
}

void		hit_cone(t_object *cone, t_point o, t_point d)
{
	double	a;
	double	b;
	double	c;
	double	k;

	k = 1 + pow(tan(cone->angle), 2);
	a = scalar(d, d) - k * pow(scalar(d, cone->l), 2);
	b = scalar(vector(cone->c, o), d) - k * scalar(d, cone->l)
			* scalar(vector(cone->c, o), cone->l);
	c = scalar(vector(cone->c, o), vector(cone->c, o))
			- k * pow(scalar(vector(cone->c, o), cone->l), 2);
	quadr_eq_solve(a, b, c, &cone->root);
}

void		hit_plane(t_object *plane, t_point o, t_point d)
{
	plane->root.t1 = -scalar(vector(plane->c, o), plane->l)
			/ scalar(d, plane->l);
}
