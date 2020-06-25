/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 09:20:28 by mdirect           #+#    #+#             */
/*   Updated: 2020/06/25 09:18:58 by estel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double		scalar(t_point a, t_point b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

double		modul(t_point a)
{
	return (sqrt(a.x * a.x + a.y * a.y + a.z * a.z));
}

t_point		multi(double k, t_point a)
{
	a.x *= k;
	a.y *= k;
	a.z *= k;
	return (a);
}

t_point		summa(t_point a, t_point b)
{
	b.x += a.x;
	b.y += a.y;
	b.z += a.z;
	return (b);
}

t_point		vector(t_point a, t_point b)
{
	b.x -= a.x;
	b.y -= a.y;
	b.z -= a.z;
	return (b);
}
