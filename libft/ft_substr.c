/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:33:32 by sogabrie          #+#    #+#             */
/*   Updated: 2023/01/22 21:03:55 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*pod;
	size_t		s_len;

	i = 0;
	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (start > s_len)
		return (ft_strdup(""));
	if (len > s_len)
		len = s_len;
	pod = malloc(sizeof(char) * (len + 1));
	if (!pod)
		return (0);
	while (s[start] != '\0' && i < len)
	{
		pod[i] = s[start];
		i++;
		start++;
	}
	pod[i] = 0;
	return (pod);
}
