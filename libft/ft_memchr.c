/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafounas <aafounas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:05:04 by aafounas          #+#    #+#             */
/*   Updated: 2025/04/30 17:05:06 by aafounas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	if (n != '\0')
		while (n--)
			if (*(unsigned char *)s++ == (unsigned char)c)
				return ((void *)(unsigned char *)s - 1);
	return (NULL);
}
