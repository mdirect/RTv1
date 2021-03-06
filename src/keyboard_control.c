/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdean <hdean@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 13:00:20 by mdirect           #+#    #+#             */
/*   Updated: 2020/06/25 09:18:58 by estel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "keys.h"

void		push_control(t_param_window *p)
{
	mlx_hook(p->window, 17, (1L << 17), x_close, NULL);
	mlx_hook(p->window, 2, (1L << 2), push_key, p);
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
