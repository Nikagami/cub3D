/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafounas <aafounas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:11:40 by aafounas          #+#    #+#             */
/*   Updated: 2025/04/30 17:11:41 by aafounas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*reallocate_memory(void *ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;

	if (!ptr)
		return (NULL);
	if (old_size == new_size)
		return (ptr);
	if (old_size > new_size)
		old_size = new_size;
	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (free(ptr), NULL);
	ft_bzero(new_ptr, new_size);
	ft_memcpy(new_ptr, ptr, old_size);
	free(ptr);
	return (new_ptr);
}
