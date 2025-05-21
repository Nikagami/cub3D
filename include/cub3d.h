/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafounas <aafounas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:02:37 by aafounas          #+#    #+#             */
/*   Updated: 2025/04/30 17:02:40 by aafounas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include <stdio.h>
# include <MLX42/MLX42.h>
# include <glad/glad.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>
# include <KHR/khrplatform.h>
# include <limits.h>
# include <stdbool.h>
# include <MLX42/MLX42_Int.h>
# include <lodepng/lodepng.h>
# include <unistd.h>
# include <cuberr.h>

# ifndef PI
#  define PI 3.14159265358979323846
# endif

# ifndef HEIGHT
#  define HEIGHT 450
# endif

# ifndef WIDTH
#  define WIDTH 800
# endif

# ifndef BLOCK
#  define BLOCK 128
# endif

# ifndef STEPSIZE
#  define STEPSIZE 16
# endif

# ifndef MAX_FLAG_SIZE
#  define MAX_FLAG_SIZE 6
# endif

# ifndef FLT_MAX
#  define FLT_MAX 3.40282347e+38F
# endif

typedef union u_pixel
{
	struct
	{
		unsigned char	r;
		unsigned char	g;
		unsigned char	b;
		unsigned char	a;
	};
	unsigned int		hex;
	unsigned char		rgba[4];
}	t_pixel;

typedef enum e_map_element
{
	NORTH_WALL_TEXTURE = 0,
	EAST_WALL_TEXTURE = 1,
	SOUTH_WALL_TEXTURE = 2,
	WEST_WALL_TEXTURE = 3,
	CEILING_COLOR,
	FLOOR_COLOR,
}	t_map_element;

typedef enum e_parse_state
{
	MAP_CONTENT = 0,
	MAP_FLAG,
	INVALID_ELEMENT,
}	t_parse_state;

typedef enum e_player_direction
{
	DIR_NORTH = 0,
	DIR_EAST = 1,
	DIR_SOUTH = 2,
	DIR_WEST = 3,
}	t_player_direction;

typedef struct s_map_line
{
	char				*content;
	t_parse_state		state;
	struct s_map_line	*next;
}	t_map_line;

typedef struct s_location
{
	size_t	x;
	size_t	y;
}	t_location;

typedef struct s_raycast
{
	float		ray_length;
	float		corrected_length;
	float		ray_angle;
	float		hit_point_x;
	float		hit_point_y;
	float		wall_height;
	uint8_t		wall_texture_id;
	mlx_image_t	*current_slice;
	mlx_image_t	*next_slice;
}	t_raycast;

typedef struct s_player
{
	t_location	spawn_position;
	float		position[2];
	float		view_angle;
	float		move_delta_x;
	float		move_delta_y;
	float		projection_plane;
	t_raycast	*rays;
	size_t		ray_count;
}	t_player;

typedef union u_wall_textures
{
	struct
	{
		mlx_texture_t	*north_texture;
		mlx_texture_t	*south_texture;
		mlx_texture_t	*west_texture;
		mlx_texture_t	*east_texture;
	};
	mlx_texture_t		*textures_array[4];
}	t_wall_textures;

typedef struct s_map
{
	t_wall_textures	*walls;
	t_pixel			*f;
	t_pixel			*c;
	char			**map;
}	t_map;

typedef struct s_data
{
	t_map		*map_data;
	mlx_t		*mlx;
	mlx_image_t	*ceiling_image;
	mlx_image_t	*floor_image;
	mlx_image_t	*display_buffer;
	t_player	*player_info;
	bool		mouse_enabled;
	bool		show_fps;
}	t_data;

t_map_line	*find_list_node(t_map_line **head, t_parse_state state);
t_map_line	*create_list_node(char *content, t_parse_state state);
void		free_list(t_map_line **lst);
void		append_list_node(t_map_line **head, t_map_line *new_node);
t_location	find_character_position(char **map, char *charset);
char		*remove_whitespace(char *str);
void		remove_newline(char *str);
bool		initialize_game_data(t_data *game, mlx_t *mlx, t_map *map_data);
void		calculate_ray_properties(mlx_image_t *screen, t_player *player,
				char **map);
void		init_window(t_data *data);
void		rotate_player(t_data *data, bool left);
void		handle_player_input(void *param);
void		update_display(t_data *data);
float		ray_len(t_player *player, size_t i, char **map);
void		toggle_settings(mlx_key_data_t keydata, void *param);
bool		check_collision_x(t_data *data, char **map, float tempx);
bool		check_collision_y(t_data *data, char **map, float tempy);
int			apply_function_to_array(char **array, int (*func)(char *, int));
int			check_file_access(char *filename);
int			validate_file_type(char *filename, char *expected_extension);
int			is_string_empty(char *str);
char		**import_file_content(int fd);
char		**load_map_file(char *filename);
char		*extract_identifier_value(char **arr, const char *flag);
int			is_valid_identifier(char *str);
int			validate_map_layout(char **map);
int			count_player_positions(char **str);
t_map		*parse_map_content(char *filename);
int			check_identifier_uniqueness(char **arr, const char *flag);
size_t		count_character_occurrences(char *str, char target);
void		fill_image_color(mlx_image_t *image, t_pixel *color, size_t size);
void		free_string_array(char **array);
void		free_data(t_data *cub);
void		free_player(t_player *player);
void		free_map(t_map *map);
float		calculate_horizontal_left_distance(t_player *player,
				size_t ray_index, char **map);
float		calculate_horizontal_right_distance(t_player *player,
				size_t ray_index, char **map);
float		calculate_vertical_down_distance(t_player *player,
				size_t ray_index, char **map);
float		calculate_vertical_up_distance(t_player *player,
				size_t ray_index, char **map);
void		set_wall_texture(t_player *player, size_t ray_index,
				float dist_x, float dist_y);
t_map_line	*parse_map_file(int fd);
int			count_state_occurrences(t_map_line **head, t_parse_state state);
void		free_string_arrayyy(char **array);
size_t		ft_arrlen(char **arr);
int			get_r(int color);
int			get_g(int color);
int			get_b(int color);
int			get_a(int color);
int			get_rgba(int r, int g, int b, int a);
int			ft_isspace(char c);
bool		ft_isnumber(const char *string);
t_pixel		*ft_newcolor(int r, int g, int b, int a);
void		*reallocate_memory(void *ptr, size_t old_size, size_t new_size);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strcmp(char *s1, char *s2);
char		**duplicate_string_array(char **src);

#endif