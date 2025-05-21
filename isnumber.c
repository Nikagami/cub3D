/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isnumber.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafounas <aafounas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:01:13 by aafounas          #+#    #+#             */
/*   Updated: 2025/04/30 17:01:15 by aafounas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	ft_isnumber(const char *string)
{
	int		i;

	i = 0;
	if (!string || !*string)
		return (false);
	if (string[i] == '-' || string[i] == '+')
		i++;
	while (string[i])
	{
		if (!ft_isdigit(string[i]))
			return (false);
		i++;
	}
	return (true);
}
