/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdean <hdean@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 12:41:49 by mdirect           #+#    #+#             */
/*   Updated: 2020/06/25 09:18:58 by estel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		main(int argc, char **argv)
{
	t_param_window	p;

	if (argc != 2)
		return (ft_usage());
	read_scene(argv[1], &p.scene);
	create_windows(&p);
	draw(&p);
	push_control(&p);
	mlx_loop(p.mlx);
	free(p.scene.obj);
	free(p.scene.light);
	return (0);
}
