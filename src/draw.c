/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdean <hdean@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 14:19:22 by mdirect           #+#    #+#             */
/*   Updated: 2020/06/25 09:18:58 by estel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		closest(t_scene *s, t_point o, t_point d)
{
	int		i;
	double	cls_t;
	int		cls_sph;

	cls_t = INFINITY;
	cls_sph = -1;
	i = -1;
	while (++i < s->obj_quant)
	{
		hit_figures(&s->obj[i], o, d);
		if (s->obj[i].root.t1 < cls_t && s->scope.min < s->obj[i].root.t1 &&
		s->obj[i].root.t1 < s->scope.max)
		{
			cls_t = s->obj[i].root.t1;
			cls_sph = i;
		}
		if (s->obj[i].root.t2 < cls_t && s->scope.min < s->obj[i].root.t2 &&
		s->obj[i].root.t2 < s->scope.max)
		{
			cls_t = s->obj[i].root.t2;
			s->obj[i].root.t1 = s->obj[i].root.t2;
			cls_sph = i;
		}
	}
	return (cls_sph);
}

double	intensive(t_scene *s, t_point v, int i, int j)
{
	double	intens;
	double	tmp;
	t_point	vec;

	intens = 0;
	vec = s->light[j].type == 1 ? vector(s->obj[i].p, s->light[j].c)
			: s->light[j].c;
	s->scope.max = s->light[j].type == 1 ? 1.0 : INFINITY;
	if (closest(s, s->obj[i].p, vec) != -1)
		return (intens);
	if ((tmp = scalar(s->obj[i].n, vec)) > 0)
		intens += s->light[j].intens * tmp / (modul(s->obj[i].n)
				* modul(vec));
	if (s->obj[i].specular != -1)
	{
		vec = vector(vec, multi(2.0
		* scalar(vec, s->obj[i].n), s->obj[i].n));
		if ((tmp = scalar(vec, v)) > 0)
			intens += s->light[j].intens * pow(tmp /
					(modul(vec) * modul(v)), s->obj[i].specular);
	}
	return (intens);
}

double	make_color(t_scene *s, t_point v, int i)
{
	double	intens;
	int		j;

	intens = 0;
	j = -1;
	while (++j < s->light_quant)
		if (s->light[j].type == 0)
			intens += s->light[j].intens;
		else
			intens += intensive(s, v, i, j);
	return (intens);
}

t_point	rt(t_scene *s, t_point o, t_point d, int depth)
{
	int			c_s;
	t_point		color;
	t_point		r_c;
	t_point		r_r;

	if ((c_s = closest(s, o, d)) == -1)
		return (s->bg_color);
	s->obj[c_s].p = summa(o, multi(s->obj[c_s].root.t1, d));
	normal(&s->obj[c_s], o, d);
	color = multi(make_color(s, multi(-1, d), c_s), s->obj[c_s].color);
	if (s->obj[c_s].mirror <= 0 || depth <= 0)
		return (color);
	r_r = vector(multi(-1, d), multi(2 * scalar(multi(-1, d), s->obj[c_s].n),
			s->obj[c_s].n));
	s->scope.min = E;
	s->scope.max = INFINITY;
	r_c = rt(s, s->obj[c_s].p, r_r, depth - 1);
	return (summa(multi(1 - s->obj[c_s].mirror, color),
			multi(s->obj[c_s].mirror, r_c)));
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
			p->scene.scope.min = E;
			p->scene.scope.max = INFINITY;
			p->img_data[j * WIN_X + i] = check_color(rt(&p->scene, p->scene.o,
					rotate_matrix(&p->scene, (t_point) {x, y, 1}), DEPTH));
		}
	}
	mlx_put_image_to_window(p->mlx, p->window, p->img, 0, 0);
}
