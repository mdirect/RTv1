/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 13:00:20 by mdirect           #+#    #+#             */
/*   Updated: 2020/04/09 21:27:26 by estel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		push_control(t_param_window *p)
{
	mlx_hook(p->window, 17, 0, x_close, p);
	mlx_hook(p->window, 2, 0, push_key, p);
//	mlx_hook(p->window, 4, 0, push_mouse, p);
//	mlx_hook(p->window, 5, 0, repush_mouse, p);
//	mlx_hook(p->window, 6, 0, move_mouse, p);
}

void		move_camera(int key, t_param_window *p)
{
	if (key == 3)
		p->scene.o.x -= 0.25;
	if (key == 15)
		p->scene.o.x += 0.25;
	if (key == 5)
		p->scene.o.y -= 0.25;
	if (key == 17)
		p->scene.o.y += 0.25;
	if (key == 4)
		p->scene.o.z -= 0.25;
	if (key == 16)
		p->scene.o.z += 0.25;
	draw(p);
}

int			push_key(int key, t_param_window *p)
{
	(void)p;
	if (key == 53)
		exit(0);
	if ((key >= 0 && key <= 2) || (key >= 12 && key <= 14))
		move_rotate(key, p);
	if ((key >= 3 && key <= 5) || (key >= 15 && key <= 17))
		move_camera(key, p);
	return (0);
}

int			x_close(void *param)
{
	(void)param;
	exit(0);
}
