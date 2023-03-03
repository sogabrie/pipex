/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:24:42 by sogabrie          #+#    #+#             */
/*   Updated: 2023/01/22 23:43:31 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i1;
	size_t	i2;
	size_t	j;
	size_t	g;

	i2 = ft_strlen(src);
	g = 0;
	if (!size)
		return (i2);
	i1 = ft_strlen(dest);
	if (size <= i1)
		return (i2 + size);
	j = i1;
	while (g < size - i1 - 1 && src[g] != '\0')
	{
		dest[j] = src[g];
		++j;
		++g;
	}
	dest[j] = '\0';
	return (i1 + i2);
}
