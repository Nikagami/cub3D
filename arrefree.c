/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrefree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafounas <aafounas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:00:30 by aafounas          #+#    #+#             */
/*   Updated: 2025/04/30 17:00:32 by aafounas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>

void	free_string_arrayyy(char **array)
{
	size_t	i;

	if (!array || !*array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
