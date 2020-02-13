/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 12:41:49 by mdirect           #+#    #+#             */
/*   Updated: 2020/02/13 15:06:46 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void 	make_scene(t_scene *scene)
{
	scene->sph.c.x = 0.0;
	scene->sph.c.y = 0.0;
	scene->sph.c.z = 0.0;
	scene->sph.r = 0.4;
}

int		main(int argc, char **argv)
{
	t_param_window	p;
	t_scene			scene;

	
	if (argc != 1)
		return (ft_usage());
	argv[1] = NULL;

	create_windows(&p);
	make_scene(&scene);
	draw(&p, &scene);
//	compile_cl(&p);
	push_control(&p);
	mlx_loop(p.mlx);
	return (0);
}
