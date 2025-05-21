/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafounas <aafounas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:02:54 by aafounas          #+#    #+#             */
/*   Updated: 2025/04/30 17:02:56 by aafounas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_dynamic_array
{
	char	**elements;
	int		current_size;
	int		element_size;
	int		capacity;
}	t_dynamic_array;

#endif