/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_figures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 11:32:33 by mdirect           #+#    #+#             */
/*   Updated: 2020/02/24 11:34:55 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double 			hit_sphere(t_scene *scene, t_point d)
{
	double a;
	double b;
	double c;

	a = scalar(vector(scene->o, d), vector(scene->o, d));
	b = scalar(vector(scene->sph.c, scene->o), vector(scene->o, d));
	c = scalar(vector(scene->sph.c, scene->o), vector(scene->sph.c, scene->o)) -
		(scene->sph.r * scene->sph.r);
	return ((quadr_eq_solve(a, b, c) == 1) ? 1 : 0);
}
