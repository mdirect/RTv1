/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdean <hdean@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 19:04:02 by hdean             #+#    #+#             */
/*   Updated: 2020/06/21 19:00:47 by hdean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		ft_strcmp_head(const char *str, const char *head)
{
	int i;

	if (!str || !head)
		return (0);
	i = 0;
	while (head[i])
	{
		if (ft_tolower(head[i]) != str[i])
			return (0);
		i++;
	}
	return (1);
}

int		ft_isspace(char ch)
{
	return (ch == ' ' || ch == '\f' || ch == '\n' || ch == '\r' ||
                                                    ch == '\t' || ch == '\v');
}

int		ft_issign(char ch)
{
	return (ch == '-' || ch == '+');
}

void	delete_list(t_lines **list)
{
	t_lines		*tmp;
	t_lines		*next_list;

	tmp = *list;
	while (tmp)
	{
		next_list = tmp->next;
		if (tmp->line)
			free(tmp->line);
		free(tmp);
		tmp = next_list;
	}
	*list = NULL;
}
