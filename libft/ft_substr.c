/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafounas <aafounas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:07:56 by aafounas          #+#    #+#             */
/*   Updated: 2025/04/30 17:07:58 by aafounas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len || !len)
	{
		ret = (char *)ft_calloc(1, sizeof(char));
		if (!ret)
			return (NULL);
		return (ret);
	}
	if (len >= s_len)
		len = s_len - start;
	else if (len > s_len - start)
		len--;
	ret = (char *)ft_calloc((len + 1), sizeof(char));
	if (!ret)
		return (NULL);
	s += start + (len - 1);
	ret += len;
	while (len--)
		*--ret = *s--;
	return (ret);
}
