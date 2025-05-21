/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newcolor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafounas <aafounas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:02:02 by aafounas          #+#    #+#             */
/*   Updated: 2025/04/30 17:02:04 by aafounas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	_is_color(int character)
{
	if (character >= 0 && character <= 255)
		return (1);
	return (0);
}

t_pixel	*ft_newcolor(int r, int g, int b, int a)
{
	t_pixel	*pixel;

	if (!_is_color(r) || !_is_color(g) || !_is_color(b) || !_is_color(a))
		return (NULL);
	pixel = malloc(sizeof(t_pixel));
	if (!pixel)
		return (NULL);
	pixel->r = r;
	pixel->g = g;
	pixel->b = b;
	pixel->a = a;
	return (pixel);
}
