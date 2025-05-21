/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafounas <aafounas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:00:50 by aafounas          #+#    #+#             */
/*   Updated: 2025/04/30 17:00:52 by aafounas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_map(t_map	*map)
{
	mlx_delete_texture(map->walls->north_texture);
	mlx_delete_texture(map->walls->south_texture);
	mlx_delete_texture(map->walls->west_texture);
	mlx_delete_texture(map->walls->east_texture);
	if (map->walls)
		free(map->walls);
	if (map->f)
		free(map->f);
	if (map->c)
		free(map->c);
	if (map->map)
		free_string_array(map->map);
	if (map)
		free(map);
}

void	free_player(t_player *player)
{
	if (player)
	{
		free(player->rays);
		free(player);
	}
}

void	free_data(t_data *cub)
{
	if (cub->map_data)
		free_map(cub->map_data);
	if (cub->ceiling_image && cub->mlx)
		mlx_delete_image(cub->mlx, cub->ceiling_image);
	if (cub->floor_image && cub->mlx)
		mlx_delete_image(cub->mlx, cub->floor_image);
	if (cub->display_buffer && cub->mlx)
		mlx_delete_image(cub->mlx, cub->display_buffer);
	if (cub->player_info)
		free_player(cub->player_info);
	if (cub->mlx)
		mlx_terminate(cub->mlx);
}
