/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_figures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 11:32:33 by mdirect           #+#    #+#             */
/*   Updated: 2020/03/03 16:21:39 by estel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			hit_sphere(t_scene *scene, t_point d)
{
	double a;
	double b;
	double c;

	a = scalar(vector(scene->o, d), vector(scene->o, d));
	b = scalar(vector(scene->sph.c, scene->o), vector(scene->o, d));
	c = scalar(vector(scene->sph.c, scene->o), vector(scene->sph.c, scene->o)) -
		(scene->sph.r * scene->sph.r);
	scene->sph.t = quadr_eq_solve(a, b, c);
	scene->sph.p = summa(multi(scene->sph.t, vector(scene->o, d)), scene->o);
	scene->sph.n = vector(scene->sph.p, scene->sph.c);
	scene->sph.n = multi((1.0 / scene->sph.r), scene->sph.n);
	return ((scene->sph.t > 1.0) ? 1 : 0);
}
