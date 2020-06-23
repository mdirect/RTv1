/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdean <hdean@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 12:41:49 by mdirect           #+#    #+#             */
/*   Updated: 2020/06/22 00:50:24 by hdean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		main(int argc, char **argv)
{
	t_param_window	p;

	if (argc != 2)
		return (ft_usage());
	printf("%s\n", argv[1]);
	read_scene(argv[1], &p.scene);
	create_windows(&p);
	draw(&p);
	push_control(&p);
	mlx_loop(p.mlx);
	free(p.scene.obj);
	free(p.scene.light);
	return (0);
}
