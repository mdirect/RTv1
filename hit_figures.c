/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_figures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 11:32:33 by mdirect           #+#    #+#             */
/*   Updated: 2020/04/06 23:37:32 by estel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		hit_sphere(t_sphere *sph, t_point o, t_point d)
{
	double a;
	double b;
	double c;

	a = scalar(d, d);
	b = scalar(vector(sph->c, o), d);
	c = scalar(vector(sph->c, o), vector(sph->c, o)) - (sph->r * sph->r);
	quadr_eq_solve(a, b, c, &sph->t[0], &sph->t[1]);
}
