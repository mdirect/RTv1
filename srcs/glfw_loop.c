/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glfw_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 21:28:31 by epainter          #+#    #+#             */
/*   Updated: 2020/01/30 15:10:36 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	glfw_loop(t_params params)
{
	while (!glfwWindowShouldClose(params.p_glfw.window))
	{
		/* Render here */

		/* Swap front and back buffers */
		glfwSwapBuffers(params.p_glfw.window);

		/* Poll for and process events */
		glfwPollEvents();
	}
	glfwDestroyWindow(params.p_glfw.window);
	glfwTerminate();
}