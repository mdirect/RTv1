/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 13:00:08 by mdirect           #+#    #+#             */
/*   Updated: 2019/09/28 22:16:50 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t n;

	n = ft_strlen(dst);
	if (n > size)
		return (size + ft_strlen(src));
	i = 0;
	if (size > n)
	{
		while (src[i] && (n + i) < size - 1)
		{
			dst[n + i] = src[i];
			i++;
		}
		dst[n + i] = '\0';
	}
	return (n + ft_strlen(src));
}
