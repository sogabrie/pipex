/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 23:38:46 by sogabrie          #+#    #+#             */
/*   Updated: 2023/01/22 23:39:45 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*de;

	if (!del || !lst || !*lst)
		return ;
	while (*lst)
	{
		de = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = de;
	}
}
