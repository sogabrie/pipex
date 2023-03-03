/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:57:20 by sogabrie          #+#    #+#             */
/*   Updated: 2023/01/21 19:15:34 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	itnum(char *mas, long n, int i)
{
	mas[i] = 0;
	--i;
	if (n == 0)
	{
		mas[0] = 48;
		mas[1] = 0;
		return ;
	}
	while (n > 0 && i >= 0)
	{
		mas[i] = (n % 10) + 48;
		n = n / 10;
		--i;
	}
}

void	it(char *mas, long n)
{
	int	i;
	int	num;

	i = 0;
	num = n;
	while (num)
	{
		num = num / 10;
		++i;
	}
	if (n < 0)
	{
		mas[0] = '-';
		++i;
		n *= -1;
	}
	itnum(mas, n, i);
}

char	*ft_itoa(int n)
{
	long	n2;
	char	*num;
	char	mas[15];

	n2 = n;
	it(mas, n2);
	num = ft_strdup(mas);
	if (!num)
		return (0);
	return (num);
}
