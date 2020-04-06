/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 14:19:22 by mdirect           #+#    #+#             */
/*   Updated: 2020/04/06 23:43:17 by estel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			closest(t_param_window *p, t_point o, t_point d, double min_t, double max_t)
{
	int		i;
	double	cls_t;
	int		cls_sph;

	cls_t = INFINITY;
	cls_sph = -1;
	i = -1;
	while (++i < SPH_C)
	{
		hit_sphere(&p->scene.sph[i], o, d);
		if (p->scene.sph[i].t[0] < cls_t && min_t < p->scene.sph[i].t[0] &&
			p->scene.sph[i].t[0] < max_t)
		{
			cls_t = p->scene.sph[i].t[0];
			cls_sph = i;
		}
		if (p->scene.sph[i].t[1] < cls_t && min_t < p->scene.sph[i].t[1] &&
			p->scene.sph[i].t[1] < max_t)
		{
			cls_t = p->scene.sph[i].t[1];
			p->scene.sph[i].t[0] = p->scene.sph[i].t[1];
			cls_sph = i;
		}
	}
	return (cls_sph);
}

__uint32_t	make_color(t_param_window *p, int i, t_point v)
{
	double	intens;
	t_point l;
	t_point r;
	double 	scal;
	double 	scal_r;
	int 	j;
	double 	t_max;

	intens = 0;
	l = (t_point){0.0, 0.0, 0.0};
	j = -1;
	while (++j < LIGHT_C)
	{
		if (p->scene.light[j].type == 0)
			intens += p->scene.light[j].intens;
		else if (p->scene.light[j].type == 1)
		{
			l = vector(p->scene.sph[i].p, p->scene.light[j].c);
			t_max = 1.0;
		}
		else
		{
			l = p->scene.light[j].c;
			t_max = INFINITY;
		}
		scal = scalar(l, p->scene.sph[i].n);

		if (closest(p, p->scene.sph[i].p, l, E, t_max) != -1)
			continue;

		if (scal > 0)
			intens += p->scene.light[j].intens * scal /
					  (modul(p->scene.sph[i].n) * modul(l));

		if (p->scene.sph[i].specular != -1)
		{
			r = vector(l, multi(2.0 * scal, p->scene.sph[i].n));
			scal_r = scalar(v, r);
			if (scal_r > 0)
				intens += p->scene.light[j].intens * pow(scal_r / (modul(r) * modul(v)), p->scene.sph[i].specular);
		}
	}
	return (k_color(intens, p->scene.sph[i].color));
}

__uint32_t	rt(t_param_window *p, double x, double y)
{
	int		cls_sph;

	if ((cls_sph = closest(p, p->scene.o, (t_point) {x, y, 1}, 1, INFINITY)) == -1)
		return (p->scene.bg_color);
	p->scene.sph[cls_sph].p = summa(multi(p->scene.sph[cls_sph].t[0], (t_point) {x, y, 1}), p->scene.o);
	p->scene.sph[cls_sph].n = vector(p->scene.sph[cls_sph].c, p->scene.sph[cls_sph].p);
	p->scene.sph[cls_sph].n = multi((1.0 / p->scene.sph[cls_sph].r), p->scene.sph[cls_sph].n);
	return (make_color(p, cls_sph, (t_point) {-x, -y, -1}));
}

void		draw(t_param_window *p)
{
	int		i;
	int		j;
	double	x;
	double	y;

	j = -1;
	while (++j < WIN_Y)
	{
		i = -1;
		while (++i < WIN_X)
		{
			x = (-WIN_X / 2 + (double)i) * (1.0 / WIN_X);
			y = (WIN_Y / 2 - (double)j) * (1.0 / WIN_Y);
			p->img_data[j * WIN_X + i] = rt(p, x, y);
		}
	}
	mlx_put_image_to_window(p->mlx, p->window, p->img, 0, 0);
}
