/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafounas <aafounas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:01:05 by aafounas          #+#    #+#             */
/*   Updated: 2025/04/30 17:01:07 by aafounas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calculate_ray_properties(mlx_image_t *screen,
		t_player *player, char **map)
{
	size_t	i;

	i = 0;
	while (i < player->ray_count)
	{
		player->rays[i].ray_angle = (player->view_angle
				+ ((float) i / player->ray_count * PI / 3)) - (PI / 6);
		if (player->rays[i].ray_angle < 0)
			player->rays[i].ray_angle += (2 * PI);
		if (player->rays[i].ray_angle > (2 * PI))
			player->rays[i].ray_angle -= (2 * PI);
		player->rays[i].ray_length = ray_len(player, i, map);
		player->rays[i].corrected_length = player->rays[i].ray_length
			* cos((((float)i / (float)player->ray_count * PI / 3) - (PI / 6)));
		player->rays[i].hit_point_x = player->rays[i].ray_length
			* cos(player->rays[i].ray_angle) + player->position[0];
		player->rays[i].hit_point_y = player->rays[i].ray_length
			* sin(player->rays[i].ray_angle) + player->position[1];
		player->rays[i].wall_height = (float)(screen->height)
			* 4 / player->rays[i].corrected_length * (player->projection_plane);
		i++;
	}
}

static float	get_start_angle(char **map, t_location loc)
{
	if (!map[loc.y])
		return (-1);
	if (map[loc.y][loc.x] == 'N')
		return (3 * PI / 2);
	if (map[loc.y][loc.x] == 'E')
		return (0);
	if (map[loc.y][loc.x] == 'S')
		return (PI / 2);
	if (map[loc.y][loc.x] == 'W')
		return (PI);
	return (-1);
}

static t_player	*setup_player(t_data *game, char **map)
{
	t_player	*player;

	player = ft_calloc(1, sizeof(t_player));
	if (!player)
		return (NULL);
	player->rays = ft_calloc(WIDTH, sizeof(t_raycast));
	if (!player->rays)
		return (free(player), NULL);
	player->ray_count = WIDTH;
	player->spawn_position = find_character_position(map, "NESW");
	player->view_angle = get_start_angle(map, player->spawn_position);
	if (player->view_angle < 0)
		return (free(player), NULL);
	player->position[0] = (player->spawn_position.x * BLOCK) + (BLOCK / 2);
	player->position[1] = (player->spawn_position.y * BLOCK) + (BLOCK / 2);
	player->move_delta_x = 0;
	player->move_delta_y = 0;
	player->projection_plane = BLOCK / 2 - BLOCK / 10;
	calculate_ray_properties(game->display_buffer, player, map);
	return (player);
}

static mlx_image_t	*create_background(mlx_t *mlx, t_pixel *color)
{
	mlx_image_t	*image;

	image = mlx_new_image(mlx, mlx->width, mlx->height / 2);
	if (!image)
		return (NULL);
	fill_image_color(image, color,
		image->height * image->width * sizeof(int32_t));
	return (image);
}

bool	initialize_game_data(t_data *game, mlx_t *mlx, t_map *map_data)
{
	ft_bzero(game, sizeof(t_data));
	game->display_buffer = mlx_new_image(mlx, mlx->width, mlx->height);
	game->floor_image = create_background(mlx, map_data->f);
	game->ceiling_image = create_background(mlx, map_data->c);
	game->player_info = setup_player(game, map_data->map);
	if (!game->player_info || !game->display_buffer
		|| !game->floor_image || !game->ceiling_image)
	{
		free(game->player_info->rays);
		free(game->player_info);
		mlx_delete_image(mlx, game->display_buffer);
		mlx_delete_image(mlx, game->floor_image);
		mlx_delete_image(mlx, game->ceiling_image);
		return (false);
	}
	game->map_data = map_data;
	game->mlx = mlx;
	game->mouse_enabled = true;
	game->show_fps = false;
	return (true);
}
