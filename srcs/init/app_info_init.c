/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_info_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 21:30:35 by epainter          #+#    #+#             */
/*   Updated: 2020/01/30 15:10:36 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

VkApplicationInfo	app_info_init(void)
{
	VkApplicationInfo	app_info;

	app_info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	app_info.pApplicationName = "RTv1";
	app_info.applicationVersion = 1;
	app_info.apiVersion = VK_API_VERSION_1_0;
	app_info.pEngineName = "RTv1_engine";
	app_info.engineVersion = 1;
	app_info.pNext = NULL;
	return (app_info);
}
