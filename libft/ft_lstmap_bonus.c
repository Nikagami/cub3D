/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafounas <aafounas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:04:46 by aafounas          #+#    #+#             */
/*   Updated: 2025/04/30 17:04:48 by aafounas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_listt	*ft_lstmap(t_listt *lst, void *(*f)(void *), void (*del)(void *))
{
	t_listt	*new;
	t_listt	*newel;

	new = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst != NULL)
	{
		newel = malloc(1 * sizeof(t_listt));
		if (!newel)
		{
			ft_lstclear (&new, del);
			return (NULL);
		}
		newel->content = f(lst->content);
		newel->next = NULL;
		ft_lstadd_back (&new, newel);
		lst = lst->next;
	}
	return (new);
}
