/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wallorno.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafounas <aafounas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:09:59 by aafounas          #+#    #+#             */
/*   Updated: 2025/04/30 17:10:01 by aafounas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	calculate_horizontal_left_distance(t_player *player, size_t ray_index,
			char **map)
{
	size_t	grid_x;
	size_t	grid_y;
	float	distance_x;
	float	distance_y;

	grid_x = (size_t)(player->position[0] / (float)BLOCK);
	while (grid_x > 0)
	{
		distance_x = (player->position[0] - grid_x * BLOCK);
		distance_y = (distance_x * tan(player->rays[ray_index].ray_angle));
		if (player->rays[ray_index].ray_angle > PI)
			grid_y = (size_t)((player->position[1] - fabs(distance_y))
					/ (float)BLOCK);
		else
			grid_y = (size_t)((player->position[1] + fabs(distance_y))
					/ (float)BLOCK);
		if (grid_y >= ft_arrlen(map))
			break ;
		if (map[grid_y][grid_x - 1] == '1')
			return (sqrt(pow(distance_x, 2) + pow(distance_y, 2)));
		grid_x--;
	}
	return (FLT_MAX);
}

float	calculate_horizontal_right_distance(t_player *player, size_t ray_index,
			char **map)
{
	size_t	grid_x;
	size_t	grid_y;
	float	distance_x;
	float	distance_y;

	grid_x = (size_t)(player->position[0] / (float)BLOCK) + 1;
	grid_y = (size_t)((player->position[1]) / (float)BLOCK);
	while (grid_x < ft_strlen(map[grid_y]))
	{
		distance_x = (player->position[0] - grid_x * BLOCK);
		distance_y = (distance_x * tan(player->rays[ray_index].ray_angle));
		if (player->rays[ray_index].ray_angle > PI)
			grid_y = (size_t)((player->position[1] - fabs(distance_y))
					/ (float)BLOCK);
		else
			grid_y = (size_t)((player->position[1] + fabs(distance_y))
					/ (float)BLOCK);
		if (grid_y >= ft_arrlen(map))
			break ;
		if (map[grid_y][grid_x] == '1')
			return (sqrt(pow(distance_x, 2) + pow(distance_y, 2)));
		grid_x++;
	}
	return (FLT_MAX);
}

float	calculate_vertical_down_distance(t_player *player, size_t ray_index,
			char **map)
{
	const size_t	map_height = ft_arrlen(map);
	size_t			grid_x;
	size_t			grid_y;
	float			distance_x;
	float			distance_y;

	grid_y = (size_t)(player->position[1] / (float)BLOCK) + 1;
	while (grid_y < map_height)
	{
		distance_y = (player->position[1] - grid_y * BLOCK);
		distance_x = (distance_y / tan(player->rays[ray_index].ray_angle));
		if (player->rays[ray_index].ray_angle > (PI / 2)
			&& player->rays[ray_index].ray_angle < (3 * PI / 2))
			grid_x = (size_t)((player->position[0] - fabs(distance_x))
					/ (float)BLOCK);
		else
			grid_x = (size_t)((player->position[0] + fabs(distance_x))
					/ (float)BLOCK);
		if (grid_x >= ft_strlen(map[grid_y]))
			break ;
		if (map[grid_y][grid_x] == '1')
			return (sqrt(pow(distance_x, 2) + pow(distance_y, 2)));
		grid_y++;
	}
	return (FLT_MAX);
}

float	calculate_vertical_up_distance(t_player *player, size_t ray_index,
			char **map)
{
	size_t	grid_x;
	size_t	grid_y;
	float	distance_x;
	float	distance_y;

	grid_y = (size_t)(player->position[1] / (float)BLOCK);
	while (grid_y > 0)
	{
		distance_y = (player->position[1] - grid_y * BLOCK);
		distance_x = (distance_y / tan(player->rays[ray_index].ray_angle));
		if (player->rays[ray_index].ray_angle > (PI / 2)
			&& player->rays[ray_index].ray_angle < (3 * PI / 2))
			grid_x = (size_t)((player->position[0] - fabs(distance_x))
					/ (float)BLOCK);
		else
			grid_x = (size_t)((player->position[0] + fabs(distance_x))
					/ (float)BLOCK);
		if (grid_x >= ft_strlen(map[grid_y]))
			break ;
		if (map[grid_y - 1][grid_x] == '1')
			return (sqrt(pow(distance_x, 2) + pow(distance_y, 2)));
		grid_y--;
	}
	return (FLT_MAX);
}

void	set_wall_texture(t_player *player, size_t ray_index,
			float dist_x, float dist_y)
{
	if (dist_x < dist_y)
	{
		if (player->rays[ray_index].ray_angle > (PI / 2)
			&& player->rays[ray_index].ray_angle < (3 * PI / 2))
			player->rays[ray_index].wall_texture_id = DIR_WEST;
		else
			player->rays[ray_index].wall_texture_id = DIR_EAST;
	}
	else
	{
		if (player->rays[ray_index].ray_angle < PI)
			player->rays[ray_index].wall_texture_id = DIR_SOUTH;
		else
			player->rays[ray_index].wall_texture_id = DIR_NORTH;
	}
}
