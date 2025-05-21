/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rgba.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafounas <aafounas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:00:55 by aafounas          #+#    #+#             */
/*   Updated: 2025/04/30 17:00:57 by aafounas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_r(int color)
{
	return ((color >> 24) & 0xFF);
}

int	get_g(int color)
{
	return ((color >> 16) & 0xFF);
}

int	get_b(int color)
{
	return ((color >> 8) & 0xFF);
}

int	get_a(int color)
{
	return (color & 0xFF);
}

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}
