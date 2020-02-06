/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 21:08:49 by epainter          #+#    #+#             */
/*   Updated: 2020/02/06 13:58:36 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

//static void demo_refresh_callback(GLFWwindow* window) {
//	struct demo* demo = glfwGetWindowUserPointer(window);
//	demo_draw(demo);
//}

t_glfw	init_window(void)
{
	t_glfw	glfw_params;
	int Major, Minor, Rev;

	if (glfwInit() != 1)
	{
		write(1, "Error initializing GLFW\n", 24);
		exit(1);
	}
	glfwGetVersion(&Major, &Minor, &Rev);
	printf("GLFW %d.%d.%d initialized\n", Major, Minor, Rev);

	glfw_params.width = WIDTH;
	glfw_params.height = HEIGHT;
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	glfw_params.window = glfwCreateWindow(glfw_params.width, glfw_params.height, "RTv1", NULL, NULL);
	if (!glfw_params.window) {
		write(1, "Error creating window\n", 22);
		exit(1);
	}
	glfwSetWindowUserPointer(glfw_params.window, &glfw_params);


	glfwSetKeyCallback(glfw_params.window, push_key);
	return (glfw_params);
}
