/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 12:43:06 by mdirect           #+#    #+#             */
/*   Updated: 2020/06/08 13:58:37 by estel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	scene_1(t_scene *scene)
{
	scene->bg_color = (t_point){0, 0, 0};
	scene->o = (t_point){0.0, 0.0, 0.0};
	scene->angle = (t_point) {0, 0, 0};
	scene->light[0] = make_light(0, 0.4, (t_point){0.0, 0.0, 0.0});
	scene->light[1] = make_light(1, 0.6, (t_point){2.0, 1.0, 0.0});
	scene->light[2] = make_light(2, 0.2, (t_point){1.0, 4.0, 4.0});
	scene->obj[0] = make_sphere((t_point){-2.0, 0.0, 7.0}, 1.2,
			(t_point){0, 255, 0}, 100.0, 0.5);
	scene->obj[1] = make_sphere((t_point){-0.2, -1.0, 6.0}, 1.5,
			(t_point){255, 0, 0}, 50.0, 0.4);
	scene->obj[2] = make_sphere((t_point){2.0, 3.0, 10.0}, 1.8,
			(t_point){0, 0, 255}, 100.0, 0.6);
	scene->obj[3] = make_sphere((t_point){6.2, -1.5, 17.0}, 2.0,
			(t_point){0, 255, 255}, 10.0, 0.3);
	scene->obj[4] = make_sphere((t_point){0, -500.0, 5.0}, 499.0,
			(t_point){255, 255, 0}, 1000.0, 0.5);
}
