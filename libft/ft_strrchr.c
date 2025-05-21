/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafounas <aafounas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:07:44 by aafounas          #+#    #+#             */
/*   Updated: 2025/04/30 17:07:46 by aafounas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*result;

	result = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
			result = (char *)s;
		s++;
	}
	if (*s == (char)c)
		result = (char *)s;
	return (result);
}
