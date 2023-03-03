/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 23:38:04 by sogabrie          #+#    #+#             */
/*   Updated: 2023/01/22 23:38:13 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*nels;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	nels = ft_lstlast(*lst);
	nels->next = new;
}
