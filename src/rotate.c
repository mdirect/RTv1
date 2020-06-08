/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 12:41:49 by mdirect           #+#    #+#             */
/*   Updated: 2020/06/08 14:01:23 by estel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "keys.h"

t_point		rotate_matrix(t_scene *s, t_point d)
{
	d = rotate_x(s->angle.x, d);
	d = rotate_y(s->angle.y, d);
	d = rotate_z(s->angle.z, d);
	return (d);
}

t_point		rotate_x(double angle, t_point d)
{
	t_point res;

	res = d;
	res.y = d.y * cos(angle) - d.z * sin(angle);
	res.z = d.y * sin(angle) + d.z * cos(angle);
	return (res);
}

t_point		rotate_y(double angle, t_point d)
{
	t_point res;

	res = d;
	res.x = d.x * cos(angle) + d.z * sin(angle);
	res.z = -d.x * sin(angle) + d.z * cos(angle);
	return (res);
}

t_point		rotate_z(double angle, t_point d)
{
	t_point res;

	res = d;
	res.x = d.x * cos(angle) - d.y * sin(angle);
	res.y = d.x * sin(angle) + d.y * cos(angle);
	return (res);
}

void		move_rotate(int key, t_param_window *p)
{
	if (key == KEY_A)
		p->scene.angle.x -= 0.01;
	if (key == KEY_Q)
		p->scene.angle.x += 0.01;
	if (key == KEY_S)
		p->scene.angle.y -= 0.01;
	if (key == KEY_W)
		p->scene.angle.y += 0.01;
	if (key == KEY_D)
		p->scene.angle.z -= 0.01;
	if (key == KEY_E)
		p->scene.angle.z += 0.01;
}
