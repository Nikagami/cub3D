/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafounas <aafounas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:10:38 by aafounas          #+#    #+#             */
/*   Updated: 2025/04/30 17:10:40 by aafounas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	count_player_positions(char **str)
{
	static int	found = 0;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (ft_strchr("NEWS", str[i][j]))
				found++;
			j++;
		}
		i++;
	}
	return (found);
}

int	count_state_occurrences(t_map_line **head, t_parse_state state)
{
	t_map_line	*current;
	size_t		count;

	count = 0;
	if (!head && !*head)
		return (0);
	current = *head;
	while (current)
	{
		if (current->state == state)
			count++;
		current = current->next;
	}
	return (count);
}

static bool	validate_map_position(char **map, size_t x, size_t y)
{
	map[y][x] = '1';
	if (!map[y + 1] || !map[y][x + 1] || !map[y + 1][x]
		|| map[y][x + 1] == ' ' || map[y + 1][x] == ' '
		|| map[y][x - 1] == ' ' || map[y - 1][x] == ' ')
		return (false);
	if (map[y][x + 1] == '0')
	{
		if (!validate_map_position(map, x + 1, y))
			return (false);
	}
	if (map[y + 1][x] == '0')
	{
		if (!validate_map_position(map, x, y + 1))
			return (false);
	}
	return (true);
}

int	validate_map_layout(char **map)
{
	t_location	start_pos;

	start_pos = find_character_position(map, "NESW");
	while (start_pos.y != ft_arrlen(map))
	{
		if (start_pos.x == 0 || start_pos.y == 0)
			return (0);
		if (!validate_map_position(map, start_pos.x, start_pos.y))
			return (0);
		start_pos = find_character_position(map, "0");
	}
	return (1);
}
