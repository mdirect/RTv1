/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 17:55:39 by mdirect           #+#    #+#             */
/*   Updated: 2019/10/12 17:55:39 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char *s1, char *s2, int k)
{
	char	*new;

	new = ft_strjoin(s1, s2);
	if (k == 1 || k == 3)
	{
		free(s1);
		s1 = NULL;
	}
	if (k == 2 || k == 3)
	{
		free(s2);
		s2 = NULL;
	}
	return (new);
}
