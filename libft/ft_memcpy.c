/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:18:01 by sogabrie          #+#    #+#             */
/*   Updated: 2023/01/20 15:18:03 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *a, const void *b, size_t s)
{
	size_t	i;

	if (!a && !b)
		return (0);
	i = 0;
	while (i < s)
	{
		((unsigned char *)a)[i] = ((unsigned char *)b)[i];
		++i;
	}
	return (a);
}
