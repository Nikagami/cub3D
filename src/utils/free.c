/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafounas <aafounas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:11:29 by aafounas          #+#    #+#             */
/*   Updated: 2025/04/30 17:11:31 by aafounas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_string_array(char **array)
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
