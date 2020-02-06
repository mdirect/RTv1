/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percentage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 22:34:06 by epainter          #+#    #+#             */
/*   Updated: 2020/01/30 15:10:36 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	percentage(double start, double end, double cur)
{
	if ((end - start) == 0)
		return (0.0);
	return ((cur - start) / (end - start));
}
