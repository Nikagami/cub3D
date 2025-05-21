/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maputils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafounas <aafounas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:01:54 by aafounas          #+#    #+#             */
/*   Updated: 2025/04/30 17:01:57 by aafounas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_location	find_character_position(char **map, char *charset)
{
	t_location	position;

	position.y = 0;
	while (map[position.y])
	{
		position.x = 0;
		while (map[position.y][position.x])
		{
			if (ft_strchr(charset, map[position.y][position.x]) != NULL)
				return (position);
			position.x++;
		}
		position.y++;
	}
	return (position);
}
