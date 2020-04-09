/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 12:43:06 by mdirect           #+#    #+#             */
/*   Updated: 2020/04/09 13:51:12 by estel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "scene.h"

void	scene_2(t_scene *scene)
{
	scene->bg_color = (t_point){0, 0, 0};
	scene->o = (t_point){0.0, 0.0, 0.0};
	scene->angle = (t_point) {0, 0, 0};
	scene->light[0] = make_light(0, 0.3, (t_point){0.0, 0.0, 0.0});
	scene->light[1] = make_light(1, 0.6, (t_point){2.0, 1.0, 0.0});
	scene->light[2] = make_light(2, 0.2, (t_point){1.0, 4.0, 4.0});
	scene->sph[0] = make_sphere((t_point){-2.0, 0.0, 4.0}, 1.0,
			(t_point){0, 255, 0}, 500.0, 0.3);
	scene->sph[1] = make_sphere((t_point){0.0, -1.0, 3.0}, 1.0,
			(t_point){255, 0, 0}, 500.0, 0.2);
	scene->sph[2] = make_sphere((t_point){2.0, 0.0, 4.0}, 1.0,
			(t_point){0, 0, 255}, 10.0, 0.4);
	scene->sph[3] = make_sphere((t_point){0, -5001.0, 5.0}, 5000.0,
			(t_point){255, 255, 0}, 1000.0, 0.5);
}
