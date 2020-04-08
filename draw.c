/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 14:19:22 by mdirect           #+#    #+#             */
/*   Updated: 2020/04/08 17:31:50 by estel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		closest(t_scene *s, t_point o, t_point d, double min_t, double max_t)
{
	int		i;
	double	cls_t;
	int		cls_sph;

	cls_t = INFINITY;
	cls_sph = -1;
	i = -1;
	while (++i < SPH_C)
	{
		hit_sphere(&s->sph[i], o, d);
		if (s->sph[i].t[0] < cls_t && min_t < s->sph[i].t[0] &&
			s->sph[i].t[0] < max_t)
		{
			cls_t = s->sph[i].t[0];
			cls_sph = i;
		}
		if (s->sph[i].t[1] < cls_t && min_t < s->sph[i].t[1] &&
			s->sph[i].t[1] < max_t)
		{
			cls_t = s->sph[i].t[1];
			s->sph[i].t[0] = s->sph[i].t[1];
			cls_sph = i;
		}
	}
	return (cls_sph);
}

double	make_color(t_scene *s, t_point v, int i)
{
	double	intens;
	t_point l;
	t_point r;
	double 	s_l;
	double 	s_r;
	int 	j;
	double 	t_max;

	intens = 0;
	j = -1;
	while (++j < LIGHT_C)
	{
		if (s->light[j].type == 0)
			intens += s->light[j].intens;
		else
		{
			if (s->light[j].type == 1)
			{
				l = vector(s->sph[i].p, s->light[j].c);
				t_max = 1.0;
			} else
			{
				l = s->light[j].c;
				t_max = INFINITY;
			}
			if (closest(s, s->sph[i].p, l, E, t_max) != -1)
				continue;
			if ((s_l = scalar(s->sph[i].n, l)) > 0)
				intens += s->light[j].intens * s_l / (modul(s->sph[i].n) * modul(l));
			if (s->sph[i].specular != -1)
			{
				r = vector(l, multi(2.0 * scalar(l, s->sph[i].n), s->sph[i].n));
				if ((s_r = scalar(r, v)) > 0)
					intens += s->light[j].intens *
							  pow(s_r / (modul(r) * modul(v)),
								  s->sph[i].specular);
			}
		}
	}
	return (intens);
}

t_point	rt(t_scene *s, t_point o, t_point d, double min_t, double max_t, int depth)
{
	int			c_s;
	t_point		color;
	t_point		r_c;
	t_point		r_r;

	if ((c_s = closest(s, o, d, min_t,  max_t)) == -1)
		return (s->bg_color);
	s->sph[c_s].p = summa(o, multi(s->sph[c_s].t[0], d));
	s->sph[c_s].n = vector(s->sph[c_s].c, s->sph[c_s].p);
	s->sph[c_s].n = multi(1.0 / modul(s->sph[c_s].n), s->sph[c_s].n);
	color = multi(make_color(s, multi(-1, d), c_s), s->sph[c_s].color);
	if (s->sph[c_s].mirror <= 0 || depth <= 0)
		return (color);
	r_r = vector(multi(-1, d), multi(2 * scalar(multi(-1, d), s->sph[c_s].n), s->sph[c_s].n));
	r_c = rt(s, s->sph[c_s].p, r_r, E, INFINITY, depth - 1);
	return (summa(multi(1 - s->sph[c_s].mirror, color), multi(s->sph[c_s].mirror, r_c)));
}

void	draw(t_param_window *p)
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
			p->img_data[j * WIN_X + i] = check_color(rt(&p->scene, p->scene.o,
					(t_point) {x, y, 1}, 1.0, INFINITY, DEPTH));
		}
	}
	mlx_put_image_to_window(p->mlx, p->window, p->img, 0, 0);
}
