/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdean <hdean@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 14:04:00 by estel             #+#    #+#             */
/*   Updated: 2020/06/22 00:42:46 by hdean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_thread_args	init_thread_args(int i, int j, t_param_window *p)
{
	t_thread_args	args;

	args.vec.x = (-WIN_X / 2 + (double)i) * (1.0 / WIN_X);
	args.vec.y = (WIN_Y / 2 - (double)j) * (1.0 / WIN_Y);
	args.j = j;
	args.i = i;
	args.p = p;
	args.scope.min = E;
	args.scope.max = INFINITY;
	args.scope.depth = DEPTH;
	args.scene = p->scene;
	return (args);
}

void			*thread_func(void *arg)
{
	t_thread_args	*p;

	p = arg;
	p->vec.z = 1;
	while (p->j < WIN_Y && p->i < WIN_X)
	{
		p->vec.x = (-WIN_X / 2 + (double)p->i) * (1.0 / WIN_X);
		p->vec.y = (WIN_Y / 2 - (double)p->j) * (1.0 / WIN_Y);
		p->p->img_data[p->j * WIN_X + p->i] =
				check_color(rt(&p->scene, p->scene.o,
							rotate_matrix(&p->scene, p->vec), p->scope));
		p->i += THREADS;
		if (p->i >= WIN_X)
		{
			p->i -= WIN_X;
			p->j++;
		}
	}
	return (NULL);
}

void			init_common_thread_args(t_thread_args
								*args, bool *thread_status, t_param_window *p)
{
	ft_bzero(thread_status, sizeof(*thread_status) * THREADS);
	args[THREADS].i = 0;
	args[THREADS].p = p;
	args[THREADS].j = -1;
}
