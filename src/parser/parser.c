/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafounas <aafounas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:10:21 by aafounas          #+#    #+#             */
/*   Updated: 2025/05/03 16:57:37 by aafounas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "flags.h"

static bool	load_texture(t_wall_textures *walls, char *path,
	t_player_direction dir)
{
	mlx_texture_t	*texture;

	if (!path)
		return (false);
	texture = mlx_load_png(path);
	if (!texture)
		return (false);
	if (texture->width != texture->height)
		return (mlx_delete_texture(texture), false);
	walls->textures_array[dir] = texture;
	return (true);
}

static bool	check_array_length(char **arr, size_t max_len)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		if (ft_strlen(arr[i]) > max_len)
			return (false);
		i++;
	}
	return (true);
}

static t_pixel	*parse_color_value(char *str)
{
	t_pixel	*pixel;
	char	**rgb_values;

	if (!str)
		return (NULL);
	if (count_character_occurrences(str, ',') != 2)
		return (NULL);
	rgb_values = ft_split(remove_whitespace(str), ',');
	if (!rgb_values)
		return (cuberr(ERROR_MEMORY_ALLOCATION), NULL);
	if (ft_arrlen(rgb_values) != 3 || !check_array_length(rgb_values, 3))
		return (free_string_array(rgb_values), NULL);
	if (!ft_isnumber(rgb_values[0])
		|| !ft_isnumber(rgb_values[1])
		|| !ft_isnumber(rgb_values[2]))
		return (free_string_array(rgb_values), NULL);
	pixel = ft_newcolor(ft_atoi(rgb_values[0]),
			ft_atoi(rgb_values[1]),
			ft_atoi(rgb_values[2]), 0xFF);
	return (free_string_array(rgb_values), pixel);
}

static bool	setup_map_elements(t_map *map, char **flags)
{
	if (!map->walls)
		return (false);
	if (!load_texture(map->walls,
			extract_identifier_value(flags, TEXTURE_ID_NORTH),
			DIR_NORTH))
		return (false);
	if (!load_texture(map->walls,
			extract_identifier_value(flags, TEXTURE_ID_SOUTH),
			DIR_SOUTH))
		return (false);
	if (!load_texture(map->walls,
			extract_identifier_value(flags, TEXTURE_ID_WEST),
			DIR_WEST))
		return (false);
	if (!load_texture(map->walls,
			extract_identifier_value(flags, TEXTURE_ID_EAST),
			DIR_EAST))
		return (false);
	map->f = parse_color_value(extract_identifier_value(flags, COLOR_ID_FLOOR));
	map->c = parse_color_value(extract_identifier_value
			(flags, COLOR_ID_CEILING));
	if (!map->f || !map->c)
		return (cuberr(ERROR_COLOR_VALUEE), false);
	return (true);
}

t_map	*parse_map_content(char *filename)
{
	char	**map;
	t_map	*data;

	map = load_map_file(filename);
	if (!map)
		return (NULL);
	data = ft_calloc(1, sizeof(t_map));
	if (!data)
		return (free_string_array(map), NULL);
	data->walls = ft_calloc(1, sizeof(t_wall_textures));
	if (!setup_map_elements(data, map))
		return (free_string_array(map), free_map(data), NULL);
	data->map = duplicate_string_array(&map[6]);
	if (!data->map)
		return (free_string_array(map), free_map(data), NULL);
	return (free_string_arrayyy(map), data);
}
