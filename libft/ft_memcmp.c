/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:17:00 by sogabrie          #+#    #+#             */
/*   Updated: 2023/01/22 19:30:40 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			s;
	unsigned char	*a1;
	unsigned char	*a2;

	s = 0;
	a1 = (unsigned char *)s1;
	a2 = (unsigned char *)s2;
	while (s < n)
	{
		if (a1[s] > a2[s] || a1[s] < a2[s])
			return (a1[s] - a2[s]);
		++s;
	}
	return (0);
}
