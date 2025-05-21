/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafounas <aafounas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:05:30 by aafounas          #+#    #+#             */
/*   Updated: 2025/04/30 17:05:32 by aafounas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_start;
	const unsigned char	*src_start;

	if (!dest && !src)
		return (dest);
	if (dest == src)
		return (dest);
	dest_start = (unsigned char *)dest;
	src_start = (const unsigned char *)src;
	if (dest > src)
	{
		while (n--)
			*(dest_start + n) = *(src_start + n);
	}
	else
	{
		while (n--)
			*(dest_start++) = *(src_start++);
	}
	return (dest);
}
