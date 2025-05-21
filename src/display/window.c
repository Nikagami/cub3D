/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafounas <aafounas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:10:05 by aafounas          #+#    #+#             */
/*   Updated: 2025/04/30 17:10:06 by aafounas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	resize(int32_t width, int32_t height, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	data->floor_image->instances->y = height / 2;
	data->player_info->ray_count = width;
	free(data->player_info->rays);
	data->player_info->rays = ft_calloc(width, sizeof(t_raycast));
	if (!mlx_resize_image(data->display_buffer, width, height)
		|| !mlx_resize_image(data->ceiling_image, width, height / 2)
		|| !mlx_resize_image(data->floor_image, width, height / 2)
		|| !data->player_info->rays)
		mlx_close_window(data->mlx);
	else
		update_display(data);
}

static void	mouse(void *param)
{
	t_data			*data;
	static int32_t	x;
	static int32_t	y;

	data = (t_data *)param;
	if (data->mouse_enabled)
	{
		mlx_set_cursor_mode(data->mlx, MLX_MOUSE_HIDDEN);
		mlx_get_mouse_pos(data->mlx, &x, &y);
		if (x < data->mlx->width / 2)
			rotate_player(data, true);
		else if (x > data->mlx->width / 2)
			rotate_player(data, false);
		mlx_set_mouse_pos(data->mlx, data->mlx->width / 2,
			data->mlx->height / 2);
	}
	else
		mlx_set_cursor_mode(data->mlx, MLX_MOUSE_NORMAL);
}

static void	fps(void *param)
{
	static mlx_image_t	*fps_counter = NULL;
	mlx_t				*mlx;
	static double		old;
	double				new;
	char				*text;

	mlx = ((t_data *)param)->mlx;
	new = mlx_get_time();
	mlx_delete_image(mlx, fps_counter);
	if (new > 0 && ((t_data *)param)->show_fps == true)
	{
		text = ft_itoa((int)1.0 / (new - old));
		if (text)
			fps_counter = mlx_put_string((mlx_t *)mlx, text, 10, 10);
		if (!text || (text && !fps_counter))
		{
			mlx_delete_image(mlx, fps_counter);
			free(text);
			mlx_close_window(mlx);
		}
		free(text);
	}
	old = new;
}

static void	game_loop(void *param)
{
	const t_data	*cub = (t_data *)param;
	const t_player	*player = cub->player_info;
	static float	x = -1;
	static float	y = -1;
	static float	angle = -1;

	if (x != player->move_delta_x || y != player->move_delta_y
		|| angle != player->view_angle)
	{
		x = player->move_delta_x;
		y = player->move_delta_y;
		angle = player->view_angle;
	}
	update_display((t_data *)cub);
}

void	init_window(t_data *data)
{
	mlx_image_to_window(data->mlx, data->ceiling_image, 0, 0);
	mlx_image_to_window(data->mlx, data->floor_image, 0, data->mlx->height / 2);
	mlx_image_to_window(data->mlx, data->display_buffer, 0, 0);
	mlx_loop_hook(data->mlx, &game_loop, (void *)data);
	mlx_loop_hook(data->mlx, &handle_player_input, (void *)data);
	mlx_loop_hook(data->mlx, &fps, (void *)data);
	mlx_loop_hook(data->mlx, &mouse, (void *)data);
	mlx_resize_hook(data->mlx, &resize, (void *)data);
	mlx_key_hook(data->mlx, &toggle_settings, (void *)data);
	mlx_loop(data->mlx);
}
