/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafounas <aafounas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:08:20 by aafounas          #+#    #+#             */
/*   Updated: 2025/04/30 17:08:22 by aafounas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	found_newline(t_list *stockbuf)
{
	int		i;
	t_list	*current;

	if (stockbuf == NULL)
		return (0);
	current = ft_lst_get_last(stockbuf);
	i = 0;
	while (current->content[i])
	{
		if (current->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

t_list	*ft_lst_get_last(t_list *stockbuf)
{
	t_list	*current;

	current = stockbuf;
	while (current && current->next)
		current = current->next;
	return (current);
}

void	generate_line(char **line, t_list *stockbuf)
{
	int	i;
	int	len;

	len = 0;
	while (stockbuf)
	{
		i = 0;
		while (stockbuf->content[i])
		{
			if (stockbuf->content[i] == '\n')
			{
				len++;
				break ;
			}
			len++;
			i++;
		}
		stockbuf = stockbuf->next;
	}
	*line = malloc(sizeof(char) * (len + 1));
}

void	free_stockbuf(t_list *stockbuf)
{
	t_list	*current;
	t_list	*next;

	current = stockbuf;
	while (current)
	{
		free(current->content);
		next = current->next;
		free(current);
		current = next;
	}
}
