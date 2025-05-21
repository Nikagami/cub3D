/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafounas <aafounas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:10:31 by aafounas          #+#    #+#             */
/*   Updated: 2025/04/30 17:10:32 by aafounas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "vector.h"

static bool	init_dynamic_array( t_dynamic_array *vec, int type_size, int size)
{
	vec->current_size = 0;
	vec->capacity = size;
	vec->element_size = type_size;
	vec->elements = ft_calloc(vec->capacity, type_size);
	if (!vec->elements)
		return (false);
	return (true);
}

static bool	add_to_dynamic_array( t_dynamic_array *vec, char *str)
{
	if (vec->current_size == vec->capacity)
	{
		vec->capacity *= 2;
		vec->elements = reallocate_memory(vec->elements,
				vec->current_size * vec->element_size,
				vec->capacity * vec->element_size);
		if (!vec->elements)
			return (false);
	}
	vec->elements[vec->current_size] = ft_strdup(str);
	if (!vec->elements[vec->current_size])
		return (NULL);
	vec->current_size++;
	return (true);
}

static void	clear_dynamic_array( t_dynamic_array *vec)
{
	free(vec->elements);
	vec->elements = NULL;
	vec->element_size = 0;
	vec->current_size = 0;
	vec->capacity = 0;
}

char	**import_file_content(int fd)
{
	t_dynamic_array	vec;
	t_map_line		*map;
	t_map_line		*current;

	map = parse_map_file(fd);
	if (!map)
		return (NULL);
	if (count_state_occurrences(&map, MAP_FLAG) > MAX_FLAG_SIZE)
		return (free_list(&map), NULL);
	if (!init_dynamic_array(&vec, sizeof(char *), 32))
		return (free_list(&map), NULL);
	current = map;
	while (current)
	{
		if (is_string_empty(current->content) && current->state == MAP_CONTENT)
			return (clear_dynamic_array(&vec), free_list(&map), NULL);
		if (!add_to_dynamic_array(&vec, current->content))
			return (clear_dynamic_array(&vec), free_list(&map), NULL);
		current = current->next;
	}
	return (free_list(&map), vec.elements);
}
