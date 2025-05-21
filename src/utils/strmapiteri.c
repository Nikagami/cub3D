/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strmapiteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafounas <aafounas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:11:45 by aafounas          #+#    #+#             */
/*   Updated: 2025/04/30 17:11:47 by aafounas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	apply_function_to_array(char **array, int (*func)(char *, int))
{
	size_t	index;

	if (!*array)
		return (0);
	index = 0;
	while (array[index])
	{
		if (!func(array[index], index))
			return (0);
		index++;
	}
	return (1);
}
