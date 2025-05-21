/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafounas <aafounas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:09:42 by aafounas          #+#    #+#             */
/*   Updated: 2025/04/30 17:09:44 by aafounas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	calculate_movement_delta(t_player *player, bool is_forward)
{
	if (is_forward)
	{
		player->move_delta_x = STEPSIZE * cos(player->view_angle);
		player->move_delta_y = STEPSIZE * sin(player->view_angle);
	}
	else
	{
		player->move_delta_x = STEPSIZE * sin(player->view_angle);
		player->move_delta_y = STEPSIZE * -cos(player->view_angle);
	}
}

static void	reverse_direction(t_data *data)
{
	data->player_info->move_delta_x *= -1;
	data->player_info->move_delta_y *= -1;
}

static void	update_player_position(t_data *data, bool forward, bool is_forward)
{
	char	**map;
	float	next_x;
	float	next_y;

	calculate_movement_delta(data->player_info, is_forward);
	map = (char **) data->map_data->map;
	if (!forward)
		reverse_direction(data);
	next_x = data->player_info->position[0] + data->player_info->move_delta_x;
	next_y = data->player_info->position[1] + data->player_info->move_delta_y;
	if (check_collision_x(data, map, next_x))
		data->player_info->move_delta_x = 0;
	if (check_collision_y(data, map, next_y))
		data->player_info->move_delta_y = 0;
	data->player_info->position[0] += data->player_info->move_delta_x;
	data->player_info->position[1] += data->player_info->move_delta_y;
}

void	rotate_player(t_data *data, bool left)
{
	if (!left)
		data->player_info->view_angle += (PI / 48);
	else
		data->player_info->view_angle -= (PI / 48);
	if (data->player_info->view_angle >= (2 * PI))
		data->player_info->view_angle -= (2 * PI);
	else if (data->player_info->view_angle < 0)
		data->player_info->view_angle += (2 * PI);
}

void	handle_player_input(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		update_player_position(data, true, true);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		update_player_position(data, false, true);
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		update_player_position(data, true, false);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		update_player_position(data, false, false);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		rotate_player(data, true);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		rotate_player(data, false);
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
}
