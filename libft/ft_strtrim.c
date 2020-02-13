/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 13:51:50 by mdirect           #+#    #+#             */
/*   Updated: 2019/09/28 22:16:50 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*new;
	size_t	n;
	size_t	i;
	size_t	k;

	if (!s)
		return (NULL);
	n = ft_strlen(s) - 1;
	while ((s[n] == ' ' || s[n] == '\n' || s[n] == '\t') && n)
		n--;
	i = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && i < n)
		i++;
	if (!(new = (char*)malloc(sizeof(char) * (n - i + 2))))
		return (NULL);
	k = 0;
	if (i < n)
		while (k < n - i + 1)
		{
			new[k] = s[k + i];
			k++;
		}
	new[k] = '\0';
	return (new);
}
