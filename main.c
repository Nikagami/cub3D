/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafounas <aafounas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:01:24 by aafounas          #+#    #+#             */
/*   Updated: 2025/04/30 17:01:27 by aafounas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_data	data;
	t_map	*cu;
	mlx_t	*mlx;

	if (ac != 2)
		return (cuberr(ERROR_MISSING_ARGSS), 1);
	cu = parse_map_content(av[1]);
	if (!cu)
		return (1);
	mlx = mlx_init(WIDTH, HEIGHT, "data", true);
	if (!mlx)
		return (free_map(cu), 1);
	if (!initialize_game_data(&data, mlx, cu))
		return (cuberr(ERROR_MEMORY_ALLOCATION), free_map(cu),
			mlx_terminate(mlx), 1);
	init_window(&data);
	free_data(&data);
	return (EXIT_SUCCESS);
}
