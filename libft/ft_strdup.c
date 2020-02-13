/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 13:25:18 by mdirect           #+#    #+#             */
/*   Updated: 2019/09/28 22:16:50 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	n;
	char	*new;

	n = ft_strlen(s1);
	if (n == SIZE_MAX)
		return (NULL);
	if (!(new = (char*)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	n = 0;
	while (s1[n])
	{
		new[n] = s1[n];
		n++;
	}
	new[n] = '\0';
	return (new);
}
