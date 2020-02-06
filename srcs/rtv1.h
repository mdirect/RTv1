/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 16:15:40 by epainter          #+#    #+#             */
/*   Updated: 2020/02/02 14:13:30 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# define WIDTH 640
# define HEIGHT 480
# include <GLFW/glfw3.h>
# include <vulkan/vulkan.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

#include <stdio.h>

typedef	struct							s_vulkan_params
{
	VkApplicationInfo					app_info;
	VkInstanceCreateInfo				instance_create_info;
	VkAllocationCallbacks				p_alloc;
	VkInstance							instance;
	VkResult							result;
	uint32_t							gpu_count;
	VkPhysicalDevice					gpu;
	VkPhysicalDeviceProperties			gpu_props;
	VkPhysicalDeviceMemoryProperties	mem_properties;
	uint32_t							count_queue;
	VkQueueFamilyProperties				*queue_prop;
	VkDevice							device;
	VkDeviceCreateInfo					device_info;
}										t_vulkan;

typedef	struct							s_glfw
{
	GLFWwindow*							window;
	int									width;
	int									height;
}										t_glfw;

typedef	struct							s_params
{
	t_vulkan							p_vulkan;
	t_glfw								p_glfw;
}										t_params;

t_glfw									init_window(void);
t_params								init(void);
void									glfw_loop(t_params params);
void									init_vulkan(t_vulkan *vk);
void									vk_error(VkResult res);
VkApplicationInfo						app_info_init(void);
void									gpu_props_init(t_vulkan *vk);
void									device_init(t_vulkan *vk);
void									push_key(GLFWwindow* window, int key,
										int scancode, int action, int mods);

#endif
