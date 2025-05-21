/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafounas <aafounas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:11:12 by aafounas          #+#    #+#             */
/*   Updated: 2025/04/30 17:11:14 by aafounas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_file_access(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}

static int	check_file_extension(char *filename, char *extension)
{
	size_t	filename_len;
	size_t	extension_len;

	filename_len = ft_strlen(filename);
	extension_len = ft_strlen(extension);
	if (filename_len < extension_len)
		return (0);
	if (ft_strncmp(&filename[filename_len - extension_len],
			extension, extension_len))
		return (0);
	return (1);
}

int	validate_file_type(char *filename, char *expected_extension)
{
	int	fd;

	if (!filename)
		return (0);
	if (!check_file_extension(filename, expected_extension))
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}
