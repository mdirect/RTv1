/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 12:41:49 by mdirect           #+#    #+#             */
/*   Updated: 2020/04/09 13:34:01 by estel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

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
	if (key == 0)
		p->scene.angle.x -= 0.01;
	if (key == 12)
		p->scene.angle.x += 0.01;
	if (key == 1)
		p->scene.angle.y -= 0.01;
	if (key == 13)
		p->scene.angle.y += 0.01;
	if (key == 2)
		p->scene.angle.z -= 0.01;
	if (key == 14)
		p->scene.angle.z += 0.01;
	draw(p);
}
