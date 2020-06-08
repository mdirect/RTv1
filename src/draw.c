/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 14:19:22 by mdirect           #+#    #+#             */
/*   Updated: 2020/06/08 14:01:23 by estel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		closest(t_scene *s, t_point o, t_point d, t_scope scope)
{
	int		i;
	double	cls_t;
	int		cls_sph;

	cls_t = INFINITY;
	cls_sph = -1;
	i = -1;
	while (++i < OBJ_C)
	{
		hit_figures(&s->obj[i], o, d);
		if (s->obj[i].root.t1 < cls_t && scope.min < s->obj[i].root.t1 &&
			s->obj[i].root.t1 < scope.max)
		{
			cls_t = s->obj[i].root.t1;
			cls_sph = i;
		}
		if (s->obj[i].root.t2 < cls_t && scope.min < s->obj[i].root.t2 &&
			s->obj[i].root.t2 < scope.max)
		{
			cls_t = s->obj[i].root.t2;
			s->obj[i].root.t1 = s->obj[i].root.t2;
			cls_sph = i;
		}
	}
	return (cls_sph);
}

double	intensive(t_scene *s, t_point v, int *i, t_scope scope)
{
	double	intens;
	double	tmp;
	t_point	vec;

	intens = 0;
	vec = s->light[i[1]].type == 1 ? vector(s->obj[*i].p, s->light[i[1]].c)
								: s->light[i[1]].c;
	scope.max = s->light[i[1]].type == 1 ? 1.0 : INFINITY;
	if (closest(s, s->obj[*i].p, vec, scope) != -1)
		return (intens);
	if ((tmp = scalar(s->obj[*i].n, vec)) > 0)
		intens += s->light[i[1]].intens * tmp / (modul(s->obj[*i].n)
				* modul(vec));
	if (s->obj[*i].specular != -1)
	{
		vec = vector(vec, multi(2.0
		* scalar(vec, s->obj[*i].n), s->obj[*i].n));
		if ((tmp = scalar(vec, v)) > 0)
			intens += s->light[i[1]].intens * pow(tmp /
					(modul(vec) * modul(v)), s->obj[*i].specular);
	}
	return (intens);
}

double	make_color(t_scene *s, t_point v, int i, t_scope scope)
{
	double	intens;
	int		iters[2];

	intens = 0;
	iters[0] = i;
	iters[1] = -1;
	while (++iters[1] < LIGHT_C)
		if (s->light[iters[1]].type == 0)
			intens += s->light[iters[1]].intens;
		else
			intens += intensive(s, v, iters, scope);
	return (intens);
}

t_point	rt(t_scene *s, t_point o, t_point d, t_scope scope)
{
	int			c_s;
	t_point		color;
	t_point		r_c;
	t_point		r_r;

	if ((c_s = closest(s, o, d, scope)) == -1)
		return (s->bg_color);
	s->obj[c_s].p = summa(o, multi(s->obj[c_s].root.t1, d));
	normal(&s->obj[c_s], o, d);
	color = multi(make_color(s, multi(-1, d), c_s, scope), s->obj[c_s].color);
	if (s->obj[c_s].mirror <= 0 || scope.depth <= 0)
		return (color);
	r_r = vector(multi(-1, d), multi(2 * scalar(multi(-1, d), s->obj[c_s].n),
			s->obj[c_s].n));
	scope.min = E;
	scope.max = INFINITY;
	scope.depth--;
	r_c = rt(s, s->obj[c_s].p, r_r, scope);
	return (summa(multi(1 - s->obj[c_s].mirror, color),
			multi(s->obj[c_s].mirror, r_c)));
}

void	draw(t_param_window *p)
{
	t_thread_args	args[THREADS + 1];
	pthread_t		t[THREADS];
	bool			thread_status[THREADS];
	size_t			cur_trd;

	init_common_thread_args(args, thread_status, p);
	args[THREADS].i = -1;
	args[THREADS].j = 0;
	while (++args[THREADS].i < THREADS)
	{
		cur_trd = (args[THREADS].j * WIN_X + args[THREADS].i) % THREADS;
		if (thread_status[cur_trd] == false)
			thread_status[cur_trd] = true;
		else
			pthread_join(t[cur_trd], NULL);
		args[cur_trd] = init_thread_args(args
				[THREADS].i, args[THREADS].j, p);
		pthread_create(&t[cur_trd], NULL, &thread_func, &args[cur_trd]);
	}
	args[THREADS].i = -1;
	while (++args[THREADS].i < THREADS)
		pthread_join(t[args[THREADS].i], NULL);
	mlx_put_image_to_window(p->mlx, p->window, p->img, 0, 0);
}
