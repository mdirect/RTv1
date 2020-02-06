/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:43:25 by mdirect           #+#    #+#             */
/*   Updated: 2020/01/30 14:43:25 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	push_key(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE)
	{
		glfwSetWindowShouldClose(window, GLFW_TRUE);
		exit (0);
	}
	if (action == GLFW_RELEASE)
	{
		write(1, "You release something\n", 22);
		return ;
	}
	if (action == GLFW_PRESS)
	{
		write(1, "You press something\n", 20);
		return ;
	}
}
