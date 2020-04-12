/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_figures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 11:32:33 by mdirect           #+#    #+#             */
/*   Updated: 2020/04/12 12:23:29 by estel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	hit_figures(t_object *obj, t_point o, t_point d)
{
	if (obj->type == 1)
		hit_sphere(obj, o, d);
	if (obj->type == 2)
		hit_cylinder(obj, o, d);
}

void		hit_sphere(t_object *sph, t_point o, t_point d)
{
	double a;
	double b;
	double c;

	a = scalar(d, d);
	b = scalar(vector(sph->c, o), d);
	c = scalar(vector(sph->c, o), vector(sph->c, o)) - (sph->r * sph->r);
	quadr_eq_solve(a, b, c, &sph->t[0], &sph->t[1]);
}

void		hit_cylinder(t_object *cyl, t_point o, t_point d)
{
	double 		a;
	double 		b;
	double 		c;

	a = scalar(d, d) - pow(scalar(d, cyl->l), 2);
	b = scalar(vector(cyl->c, o), d) - scalar(d, cyl->l) * scalar(vector(cyl->c, o), cyl->l);
	c = scalar(vector(cyl->c, o), vector(cyl->c, o)) - pow(scalar(vector(cyl->c, o), cyl->l), 2) - (cyl->r * cyl->r);
	quadr_eq_solve(a, b, c, &cyl->t[0], &cyl->t[1]);
}
