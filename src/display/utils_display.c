/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafounas <aafounas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:09:53 by aafounas          #+#    #+#             */
/*   Updated: 2025/04/30 17:09:54 by aafounas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	toggle_settings(mlx_key_data_t keydata, void *param)
{
	if (keydata.key == MLX_KEY_Q && keydata.action == MLX_PRESS)
	{
		mlx_set_mouse_pos(((t_data *)param)->mlx,
			((t_data *)param)->mlx->width / 2,
			((t_data *)param)->mlx->height / 2);
		((t_data *)param)->mouse_enabled = !((t_data *)param)->mouse_enabled;
	}
	if (keydata.key == MLX_KEY_E && keydata.action == MLX_PRESS)
		((t_data *)param)->show_fps = !((t_data *)param)->show_fps;
}

bool	check_collision_x(t_data *data, char **map, float tempx)
{
	if ((data->player_info->move_delta_x > 0
			&& map[(size_t)(data->player_info->position[1]
				- data->player_info->projection_plane) / BLOCK]
		[(size_t)(tempx + data->player_info->projection_plane)
		/ BLOCK] == '1'))
		return (true);
	if ((data->player_info->move_delta_x > 0
			&& map[(size_t)(data->player_info->position[1]
				+ data->player_info->projection_plane) / BLOCK]
		[(size_t)(tempx + data->player_info->projection_plane)
		/ BLOCK] == '1'))
		return (true);
	if ((data->player_info->move_delta_x < 0
			&& map[(size_t)(data->player_info->position[1]
				- data->player_info->projection_plane) / BLOCK]
		[(size_t)(tempx - data->player_info->projection_plane)
		/ BLOCK] == '1'))
		return (true);
	if ((data->player_info->move_delta_x < 0
			&& map[(size_t)(data->player_info->position[1]
				+ data->player_info->projection_plane) / BLOCK]
		[(size_t)(tempx - data->player_info->projection_plane)
		/ BLOCK] == '1'))
		return (true);
	return (false);
}

bool	check_collision_y(t_data *data, char **map, float tempy)
{
	if ((data->player_info->move_delta_y < 0
			&& map[(size_t)(tempy - data->player_info->projection_plane)
			/ BLOCK][(size_t)(data->player_info->position[0]
		+ data->player_info->projection_plane) / BLOCK] == '1'))
		return (true);
	if ((data->player_info->move_delta_y < 0
			&& map[(size_t)(tempy - data->player_info->projection_plane)
			/ BLOCK][(size_t)(data->player_info->position[0]
		- data->player_info->projection_plane) / BLOCK] == '1'))
		return (true);
	if ((data->player_info->move_delta_y > 0
			&& map[(size_t)(tempy + data->player_info->projection_plane)
			/ BLOCK][(size_t)(data->player_info->position[0]
		+ data->player_info->projection_plane) / BLOCK] == '1'))
		return (true);
	if ((data->player_info->move_delta_y > 0
			&& map[(size_t)(tempy + data->player_info->projection_plane)
			/ BLOCK][(size_t)(data->player_info->position[0]
		- data->player_info->projection_plane) / BLOCK] == '1'))
		return (true);
	return (false);
}
