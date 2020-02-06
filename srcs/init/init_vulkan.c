/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vulkan.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 21:33:20 by epainter          #+#    #+#             */
/*   Updated: 2020/01/30 15:25:44 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft.h"

static	uint32_t	clean_info(VkInstanceCreateInfo *inst_info)
{
	ft_bzero(inst_info, sizeof(*inst_info));
	return (0);
}

void				init_vulkan(t_vulkan *vk)
{
	vk->app_info = app_info_init();
	vk->count_queue = clean_info(&vk->instance_create_info);
	vk->instance_create_info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	vk->instance_create_info.pApplicationInfo = &vk->app_info;
	vk->result = vkCreateInstance(&vk->instance_create_info, NULL, &vk->instance);
	vk_error(vk->result);
	vk->result = vkEnumeratePhysicalDevices(vk->instance, &vk->gpu_count, NULL);
	vk_error(vk->result);
	vkEnumeratePhysicalDevices(vk->instance, &vk->gpu_count, &vk->gpu);
	vk_error(vk->result);
	vkGetPhysicalDeviceProperties(vk->gpu, &vk->gpu_props);
	vkGetPhysicalDeviceMemoryProperties(vk->gpu, &vk->mem_properties);
	vkGetPhysicalDeviceQueueFamilyProperties(vk->gpu, &vk->count_queue, NULL);
	vk->queue_prop = malloc(sizeof(*vk->queue_prop) * vk->count_queue);
	vkGetPhysicalDeviceQueueFamilyProperties(vk->gpu, &vk->count_queue, vk->queue_prop);
}
