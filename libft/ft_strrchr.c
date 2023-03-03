/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:17:44 by sogabrie          #+#    #+#             */
/*   Updated: 2023/01/21 15:45:17 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*a;
	char	*a1;

	a = (char *) s;
	a1 = (char *) 0;
	while (*a != 0)
	{
		if (*a == (unsigned char)c)
			a1 = a;
		++a;
	}
	if ((unsigned char)c == 0)
		a1 = a;
	return (a1);
}
