/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafounas <aafounas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:04:27 by aafounas          #+#    #+#             */
/*   Updated: 2025/04/30 17:04:29 by aafounas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_listt *lst, void (*del)(void *))
{
	if (!lst || !del)
	{
		return ;
	}
	del(lst ->content);
	free(lst);
}
