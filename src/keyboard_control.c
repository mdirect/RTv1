/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 13:00:20 by mdirect           #+#    #+#             */
/*   Updated: 2020/06/08 14:02:09 by estel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "keys.h"

void		push_control(t_param_window *p)
{
	mlx_hook(p->window, 17, 0, x_close, NULL);
	mlx_hook(p->window, 2, 0, push_key, p);
}

void		move_camera(int key, t_param_window *p)
{
	if (key == KEY_F)
		p->scene.o.x -= 0.25;
	if (key == KEY_R)
		p->scene.o.x += 0.25;
	if (key == KEY_G)
		p->scene.o.y -= 0.25;
	if (key == KEY_T)
		p->scene.o.y += 0.25;
	if (key == KEY_H)
		p->scene.o.z -= 0.25;
	if (key == KEY_Y)
		p->scene.o.z += 0.25;
}

int			push_key(int key, t_param_window *p)
{
	if (key == ESC)
		exit(0);
	move_rotate(key, p);
	move_camera(key, p);
	draw(p);
	return (0);
}

int			x_close(void)
{
	exit(0);
}
