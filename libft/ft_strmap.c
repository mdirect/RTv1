/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 11:42:32 by mdirect           #+#    #+#             */
/*   Updated: 2019/09/28 22:16:50 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	n;
	size_t	i;
	char	*new;

	if (!s || !f)
		return (NULL);
	n = ft_strlen(s);
	if (n == SIZE_MAX)
		return (NULL);
	new = (char*)malloc(sizeof(char) * (n + 1));
	if (NULL == new)
		return (NULL);
	i = -1;
	while (++i < n)
		new[i] = (*f)(s[i]);
	new[i] = '\0';
	return (new);
}
