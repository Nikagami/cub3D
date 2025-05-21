/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafounas <aafounas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:11:17 by aafounas          #+#    #+#             */
/*   Updated: 2025/04/30 17:11:19 by aafounas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_string_array(char **array)
{
	size_t	i;

	i = 0;
	while (array && array[i])
	{
		if (array[i])
			free(array[i]);
		i++;
	}
	if (array)
		free(array);
	array = NULL;
}

char	**duplicate_string_array(char **src)
{
	size_t	i;
	char	**dest;

	if (!src || !*src)
		return (NULL);
	i = 0;
	while (src[i])
		i++;
	dest = ft_calloc(i + 1, sizeof(char *));
	i = 0;
	while (src[i])
	{
		dest[i] = ft_strdup(src[i]);
		if (!dest[i])
			free_string_array(dest);
		i++;
	}
	dest[i] = NULL;
	return (dest);
}
