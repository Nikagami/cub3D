/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafounas <aafounas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:09:37 by aafounas          #+#    #+#             */
/*   Updated: 2025/04/30 17:09:39 by aafounas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include "cub3d.h"

static size_t	calculate_texture_offset(t_raycast ray, uint32_t width)
{
	float	wall_position;

	if (ray.wall_texture_id == DIR_NORTH || ray.wall_texture_id == DIR_SOUTH)
		wall_position = ray.hit_point_x / (float)BLOCK;
	else
		wall_position = ray.hit_point_y / (float)BLOCK;
	wall_position = wall_position - floor(wall_position);
	if (ray.wall_texture_id == DIR_NORTH || ray.wall_texture_id == DIR_EAST)
		return ((size_t)(wall_position * width));
	else
		return ((size_t)((1 - wall_position) * width));
}

static uint32_t	extract_texture_pixel(mlx_texture_t *tex, size_t x, size_t y)
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;

	if (x >= tex->width || y >= tex->height)
		return (0x00000000);
	r = tex->pixels[(y * tex->width + x) * tex->bytes_per_pixel];
	g = tex->pixels[(y * tex->width + x) * tex->bytes_per_pixel + 1];
	b = tex->pixels[(y * tex->width + x) * tex->bytes_per_pixel + 2];
	a = tex->pixels[(y * tex->width + x) * tex->bytes_per_pixel + 3];
	return (get_rgba(r, g, b, a));
}

static void	render_wall_slice(mlx_image_t *scr, t_raycast ray,
		mlx_texture_t *tex, size_t rays)
{
	size_t	height;
	float	scale;
	size_t	tex_offset;

	height = 0;
	scale = (float)tex->height / (float)ray.wall_height;
	tex_offset = calculate_texture_offset(ray, tex->width);
	while (height < ray.wall_height)
	{
		if (height + ((scr->height / 2) - ray.wall_height / 2) >= 0
			&& height + ((scr->height / 2) - ray.wall_height / 2) < scr->height)
			mlx_put_pixel(scr, rays, (scr->height / 2 - ray.wall_height / 2)
				+ height, extract_texture_pixel(tex, tex_offset,
					(height + 1) * scale));
		height++;
	}
}

static void	render_walls(mlx_image_t *scr, t_raycast *rays,
		t_wall_textures *wall, size_t count)
{
	size_t			ray_index;
	mlx_texture_t	*tex;

	ray_index = 0;
	ft_bzero(scr->pixels, scr->height * scr->width * sizeof(uint32_t));
	while (ray_index < count)
	{
		tex = wall->textures_array[rays[ray_index].wall_texture_id];
		render_wall_slice(scr, rays[ray_index], tex, ray_index);
		ray_index++;
	}
}

void	update_display(t_data *data)
{
	calculate_ray_properties(data->display_buffer, data->player_info,
		data->map_data->map);
	render_walls(data->display_buffer, data->player_info->rays,
		data->map_data->walls, data->player_info->ray_count);
	data->player_info->move_delta_x = 0;
	data->player_info->move_delta_y = 0;
}
