/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 13:00:20 by mdirect           #+#    #+#             */
/*   Updated: 2020/02/13 13:58:14 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		push_control(t_param_window *p)
{
	mlx_hook(p->window, 2, 0, push_key, p);
//	mlx_hook(p->window, 4, 0, push_mouse, p);
//	mlx_hook(p->window, 5, 0, repush_mouse, p);
//	mlx_hook(p->window, 6, 0, move_mouse, p);
}

int			push_key(int key, t_param_window *p)
{
	(void)p;
	if (key == 53)
		exit(0);
	return (0);
}
