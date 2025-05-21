/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isempty.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafounas <aafounas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:11:34 by aafounas          #+#    #+#             */
/*   Updated: 2025/04/30 17:11:36 by aafounas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_string_empty(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (*str == '\n' || *str == '\0')
		return (1);
	while (ft_strchr("\t\v\f\r ", str[i]))
		i++;
	if (ft_isprint(str[i]) && str[i] != 32)
		return (0);
	return (1);
}
