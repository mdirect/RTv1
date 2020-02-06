/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 19:13:18 by epainter          #+#    #+#             */
/*   Updated: 2020/01/30 15:10:36 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int main()
{
	t_params	params;

	params = init();

	/* Make the window's context current */
	glfwMakeContextCurrent(params.p_glfw.window);
	/* Loop until the user closes the window */
	glfw_loop(params);
	return 0;
}
