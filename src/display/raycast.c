/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafounas <aafounas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:09:48 by aafounas          #+#    #+#             */
/*   Updated: 2025/04/30 17:09:50 by aafounas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	ray_len(t_player *player, size_t i, char **map)
{
	float	x;
	float	y;

	if (player->rays[i].ray_angle == (PI / 2)
		|| player->rays[i].ray_angle == (3 * PI / 2))
		x = FLT_MAX;
	else if (player->rays[i].ray_angle > (PI / 2)
		&& player->rays[i].ray_angle < (3 * PI / 2))
		x = calculate_horizontal_left_distance(player, i, map);
	else
		x = calculate_horizontal_right_distance(player, i, map);
	if (player->rays[i].ray_angle == 0
		|| player->rays[i].ray_angle == PI)
		y = FLT_MAX;
	else if (player->rays[i].ray_angle < PI)
		y = calculate_vertical_down_distance(player, i, map);
	else
		y = calculate_vertical_up_distance(player, i, map);
	set_wall_texture(player, i, x, y);
	if (x < y)
		return (x);
	else
		return (y);
}
