/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafounas <aafounas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:10:12 by aafounas          #+#    #+#             */
/*   Updated: 2025/05/03 16:57:45 by aafounas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "flags.h"

int	is_valid_identifier(char *str)
{
	if (ft_strcmp(str, TEXTURE_ID_NORTH))
		return (1);
	if (ft_strcmp(str, TEXTURE_ID_SOUTH))
		return (1);
	if (ft_strcmp(str, TEXTURE_ID_WEST))
		return (1);
	if (ft_strcmp(str, TEXTURE_ID_EAST))
		return (1);
	if (ft_strcmp(str, COLOR_ID_FLOOR))
		return (1);
	if (ft_strcmp(str, COLOR_ID_CEILING))
		return (1);
	return (0);
}

char	*extract_identifier_value(char **arr, const char *flag)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(flag);
	while (arr[i])
	{
		if (ft_strncmp(arr[i], flag, len) == 0
			&& !is_string_empty(&arr[i][len])
			&& is_valid_identifier(arr[i]))
		{
			while (ft_isspace(arr[i][len]))
				len++;
			return (&arr[i][len]);
		}
		i++;
	}
	return (NULL);
}

int	check_identifier_uniqueness(char **arr, const char *flag)
{
	size_t	i;
	size_t	len;
	int		found;

	i = 0;
	found = 0;
	len = ft_strlen(flag);
	while (arr[i])
	{
		if (found > 1)
			return (0);
		if (ft_strncmp(arr[i], flag, len) == 0
			&& !is_string_empty(&arr[i][len])
			&& is_valid_identifier(arr[i]))
			found++;
		i++;
	}
	if (!found)
		return (0);
	return (1);
}
