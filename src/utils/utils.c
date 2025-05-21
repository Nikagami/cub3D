/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafounas <aafounas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:11:51 by aafounas          #+#    #+#             */
/*   Updated: 2025/04/30 17:11:52 by aafounas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	count_character_occurrences(char *str, char target)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == target)
			count++;
		i++;
	}
	return (count);
}

char	*remove_whitespace(char *str)
{
	char	*current;

	current = str;
	while (current && *current)
	{
		if (ft_isspace(*current))
			current = ft_memmove(current, (current + 1),
					ft_strlen(current));
		else
			current++;
	}
	return (str);
}

void	remove_newline(char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return ;
	while (str[len])
		len++;
	if (str[len - 1] == '\n')
		str[len - 1] = '\0';
}

void	fill_image_color(mlx_image_t *image, t_pixel *color, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		image->pixels[i] = color->r;
		i += sizeof(int8_t);
		image->pixels[i] = color->g;
		i += sizeof(int8_t);
		image->pixels[i] = color->b;
		i += sizeof(int8_t);
		image->pixels[i] = 255;
		i += sizeof(int8_t);
	}
}
