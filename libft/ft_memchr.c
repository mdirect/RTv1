/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 15:07:15 by mdirect           #+#    #+#             */
/*   Updated: 2020/06/08 13:58:36 by estel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *cp;

	cp = (unsigned char*)s;
	while (n--)
	{
		if (*cp == (unsigned char)c)
			return (cp);
		cp++;
	}
	return (NULL);
}
