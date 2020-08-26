/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 12:43:06 by mdirect           #+#    #+#             */
/*   Updated: 2020/04/13 09:47:29 by estel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	scene_3(t_scene *scene)
{
	scene->bg_color = (t_point){0, 0, 0};
	scene->o = (t_point){0.0, 0.0, 0.0};
	scene->angle = (t_point) {0, 0, 0};
	scene->light[0] = make_light(0, 0.4, (t_point){0.0, 0.0, 0.0});
	scene->light[1] = make_light(1, 0.6, (t_point){-1.5, 1.0, 0.0});
	scene->light[2] = make_light(2, 0.2, (t_point){1.0, 4.0, 4.0});
	scene->obj[0] = make_sphere((t_point){-1.0, 0.0, 4.0}, 0.8,
			(t_point){0, 255, 0}, 100.0, 0.5);
	scene->obj[1] = make_cylinder((t_point){1.0, -1.0, 10.0}, 1.0,
			(t_point){0, 1, 0}, (t_point){255, 0, 0}, 50.0, 0.6);
	scene->obj[2] = make_cylinder((t_point){1.0, -1.0, 10.1}, 1.0,
			(t_point){1, 0, 0}, (t_point){0, 0, 255}, 500.0, 0.4);
	scene->obj[3] = make_cylinder((t_point){1.8, -1.8, 10.2}, 1.0,
			(t_point){0, 5, -12}, (t_point){150, 150, 150}, 500.0, 0.4);
}