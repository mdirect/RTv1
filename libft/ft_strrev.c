/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 19:56:48 by mdirect           #+#    #+#             */
/*   Updated: 2019/09/15 20:16:18 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_strrev(char *s)
{
	size_t	i;
	size_t	n;
	char	c;

	if (!s)
		return ;
	n = ft_strlen(s) - 1;
	i = 0;
	while (i < n)
	{
		c = s[i];
		s[i] = s[n];
		s[n] = c;
		i++;
		n--;
	}
}
