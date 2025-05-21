/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafounas <aafounas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:10:46 by aafounas          #+#    #+#             */
/*   Updated: 2025/05/03 16:57:52 by aafounas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cuberr.h"
#include "flags.h"

static int	check_texture_files(char **map)
{
	if (!validate_file_type(extract_identifier_value(map, TEXTURE_ID_NORTH),
			FILE_EXTENSION_TEXTURE))
		return (0);
	if (!validate_file_type(extract_identifier_value(map, TEXTURE_ID_SOUTH),
			FILE_EXTENSION_TEXTURE))
		return (0);
	if (!validate_file_type(extract_identifier_value(map, TEXTURE_ID_WEST),
			FILE_EXTENSION_TEXTURE))
		return (0);
	if (!validate_file_type(extract_identifier_value(map, TEXTURE_ID_EAST),
			FILE_EXTENSION_TEXTURE))
		return (0);
	return (1);
}

static int	check_required_flags(char **map)
{
	if (!check_identifier_uniqueness(map, TEXTURE_ID_NORTH))
		return (0);
	if (!check_identifier_uniqueness(map, TEXTURE_ID_SOUTH))
		return (0);
	if (!check_identifier_uniqueness(map, TEXTURE_ID_WEST))
		return (0);
	if (!check_identifier_uniqueness(map, TEXTURE_ID_EAST))
		return (0);
	if (!check_identifier_uniqueness(map, COLOR_ID_FLOOR))
		return (0);
	if (!check_identifier_uniqueness(map, COLOR_ID_CEILING))
		return (0);
	return (1);
}

static int	validate_map_content(char **map)
{
	char	**map_copy;

	map_copy = duplicate_string_array(map);
	if (!map_copy)
		return (0);
	if (count_player_positions(map_copy) != 1)
		return (free_string_arrayyy(map_copy), 0);
	if (!validate_map_layout(map_copy))
		return (free_string_arrayyy(map_copy), 0);
	return (free_string_arrayyy(map_copy), 1);
}

char	**load_map_file(char *filename)
{
	char	**map;

	if (!validate_file_type(filename, FILE_EXTENSION_MAP))
		return (cuberr(ERROR_FILE_ACCESSS), NULL);
	map = import_file_content(open(filename, O_RDONLY));
	if (!map)
		return (cuberr(ERROR_MAP_FORMATT), NULL);
	if (!check_required_flags(map))
		return (cuberr(ERROR_MISSING_REQUIRED_FLAGSS),
			free_string_arrayyy(map), NULL);
	if (!check_texture_files(map))
		return (cuberr(ERROR_TEXTURE_FORMATT), free_string_arrayyy(map), NULL);
	if (!validate_map_content(&map[6]))
		return (cuberr(ERROR_MAP_FORMATT), free_string_arrayyy(map), NULL);
	return (map);
}
