/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafounas <aafounas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:10:56 by aafounas          #+#    #+#             */
/*   Updated: 2025/04/30 17:10:57 by aafounas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map_line	*find_list_node(t_map_line **head, t_parse_state state)
{
	t_map_line	*current;

	if (!head || !*head)
		return (NULL);
	current = *head;
	while (current && current->state != state)
		current = current->next;
	return (current);
}

t_map_line	*create_list_node(char *content, t_parse_state state)
{
	t_map_line	*new_node;

	if (!content)
		return (NULL);
	new_node = malloc(sizeof(t_map_line));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->state = state;
	new_node->next = NULL;
	return (new_node);
}

void	free_list(t_map_line **lst)
{
	t_map_line	*current;
	t_map_line	*next;

	if (!lst)
		return ;
	current = *lst;
	while (current)
	{
		next = current->next;
		free(current->content);
		free(current);
		current = next;
	}
	*lst = NULL;
}

void	append_list_node(t_map_line **head, t_map_line *new_node)
{
	t_map_line	*current;

	if (!*head)
	{
		*head = new_node;
		return ;
	}
	current = *head;
	while (current->next)
		current = current->next;
	current->next = new_node;
}
