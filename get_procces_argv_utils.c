/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_procces_argv_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <sogabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 17:24:17 by sogabrie          #+#    #+#             */
/*   Updated: 2023/03/04 23:58:25 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_path(char **avp)
{
	char	*path;
	int		i;

	i = 0;
	path = 0;
	while (avp[i])
	{
		if (!ft_strncmp("PATH", avp[i], 4))
			break;
		else
			++i;
	}
	avp[i][2] = '.';
	avp[i][3] = '/';
	avp[i][4] = ':';
	return (ft_split((avp[i]) + 2, ':'));
}

char	***cat_proc(char ****proces2, char ****proces)
{
	int	i;

	i = 0;
	while ((*proces) && (*proces)[i])
	{
		(*proces2)[i] = (*proces)[i];
		++i;
	}
	free(*proces);
	*proces = 0;
	return (*proces2);
}