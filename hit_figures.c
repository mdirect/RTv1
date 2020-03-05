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

double		hit_sphere(t_scene *scene, t_point d, int i)
{
	double a;
	double b;
	double c;

	a = scalar(vector(scene->o, d), vector(scene->o, d));
	b = scalar(vector(scene->sph[i].c, scene->o), vector(scene->o, d));
	c = scalar(vector(scene->sph[i].c, scene->o), vector(scene->sph[i].c, scene->o)) -
		(scene->sph[i].r * scene->sph[i].r);
	scene->sph[i].t = quadr_eq_solve(a, b, c);
	scene->sph[i].p = summa(multi(scene->sph[i].t, vector(scene->o, d)), scene->o);
	scene->sph[i].n = vector(scene->sph[i].p, scene->sph[i].c);
	scene->sph[i].n = multi((1.0 / scene->sph[i].r), scene->sph[i].n);
	return ((scene->sph[i].t > 1.0) ? scene->sph[i].t : 0);
}
