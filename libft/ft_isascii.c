/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:10:53 by sogabrie          #+#    #+#             */
/*   Updated: 2023/01/20 15:10:58 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int a )
{
	if (a > -1 && a < 128)
		return (1);
	else
		return (0);
}