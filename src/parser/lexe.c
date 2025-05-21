/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafounas <aafounas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:10:17 by aafounas          #+#    #+#             */
/*   Updated: 2025/04/30 17:10:18 by aafounas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_valid_map_content(char *str)
{
	static bool	started = false;
	size_t		i;

	if (!str)
		return (false);
	i = 0;
	if (!started && is_string_empty(str))
		return (false);
	while (str[i])
	{
		if (!ft_isspace(str[i])
			&& str[i] != '1'
			&& str[i] != '0'
			&& !ft_strchr("NEWS", str[i])
			&& !ft_strchr("NEWS", str[i + 1]))
			return (false);
		i++;
	}
	started = true;
	return (true);
}

static bool	add_identifier_node(t_map_line **head, char *str)
{
	t_map_line	*new_element;

	if (find_list_node(head, MAP_CONTENT))
		return (free(str), false);
	if (is_string_empty(str))
		return (free(str), true);
	new_element = create_list_node(remove_whitespace(str), MAP_FLAG);
	if (!new_element)
		return (cuberr(ERROR_MEMORY_ALLOCATION), free(str), false);
	append_list_node(head, new_element);
	return (true);
}

static bool	add_map_node(t_map_line **head, char *str)
{
	t_map_line	*new_element;

	new_element = create_list_node(str, MAP_CONTENT);
	if (!new_element)
		return (free(str), false);
	append_list_node(head, new_element);
	return (true);
}

t_map_line	*parse_map_file(int fd)
{
	t_map_line	*list;
	char		*str;

	list = NULL;
	str = "\0";
	while (str)
	{
		str = get_next_line(fd);
		if (!str)
			continue ;
		remove_newline(str);
		if (is_valid_map_content(str))
		{
			if (!add_map_node(&list, str))
				return (free(str), free_list(&list), NULL);
		}
		else if (!add_identifier_node(&list, str))
			return (free_list(&list), NULL);
	}
	return (list);
}
