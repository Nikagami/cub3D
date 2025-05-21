/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafounas <aafounas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:11:22 by aafounas          #+#    #+#             */
/*   Updated: 2025/04/30 17:11:24 by aafounas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cuberr.h"
#include "cub3d.h"
#include <unistd.h>

void	cuberr(t_error_type type)
{
	if (type > 0)
		ft_putstr_fd("Error: ", 2);
	if (type == ERROR_MISSING_ARGSS)
		ft_putendl_fd(ERROR_MSG_MISSING_ARGS, STDERR_FILENO);
	if (type == ERROR_FILE_ACCESSS)
		ft_putendl_fd(ERROR_FILE_ACCESS, STDERR_FILENO);
	if (type == ERROR_MAP_FORMATT)
		ft_putendl_fd(ERROR_MAP_FORMAT, STDERR_FILENO);
	if (type == ERROR_MISSING_REQUIRED_FLAGSS)
		ft_putendl_fd(ERROR_MISSING_REQUIRED_FLAGS, STDERR_FILENO);
	if (type == ERROR_UNKNOWN_FLAGG)
		ft_putendl_fd(ERROR_UNKNOWN_FLAG, STDERR_FILENO);
	if (type == ERROR_TEXTURE_FORMATT)
		ft_putendl_fd(ERROR_TEXTURE_FORMAT, STDERR_FILENO);
	if (type == ERROR_COLOR_VALUEE)
		ft_putendl_fd(ERR_COLOR_INVALID, STDERR_FILENO);
	if (type == ERROR_MEMORY_ALLOCATION)
		ft_putendl_fd(ERR_NOT_ALLOCATE, STDERR_FILENO);
	if (type == ERROR_SUCCESS)
		ft_putendl_fd(ERR_NOT_WORKING, STDERR_FILENO);
}
