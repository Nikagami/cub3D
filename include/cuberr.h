/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cuberr.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafounas <aafounas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:02:44 by aafounas          #+#    #+#             */
/*   Updated: 2025/04/30 17:02:46 by aafounas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBERR_H
# define CUBERR_H

# define ERROR_FILE_ACCESS		"Invalid file"
# define ERROR_UNKNOWN_FLAG		"Invalid flag"
# define ERROR_MAP_FORMAT		"Invalid map"
# define ERROR_MISSING_REQUIRED_FLAGS	"Invalid flags"
# define ERR_COLOR_INVALID		"Invalid color"
# define ERROR_TEXTURE_FORMAT		"Textures cannot be loaded"
# define ERROR_MSG_MISSING_ARGS		"No argument"
# define ERR_NOT_ALLOCATE		"Not memory for allocation"
# define ERR_NOT_WORKING		"not working..."

typedef enum e_error_type
{
	ERROR_MAP_FORMATT,
	ERROR_FILE_ACCESSS,
	ERROR_COLOR_VALUEE,
	ERROR_MISSING_ARGSS = 1,
	ERROR_TEXTURE_FORMATT,
	ERROR_UNKNOWN_FLAGG,
	ERROR_MISSING_REQUIRED_FLAGSS,
	ERROR_MEMORY_ALLOCATION,
	ERROR_SUCCESS
}	t_error_type;

void	cuberr(t_error_type type);

#endif