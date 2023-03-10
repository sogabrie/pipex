/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_procces_argv_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <sogabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 17:24:17 by sogabrie          #+#    #+#             */
/*   Updated: 2023/03/07 20:03:44 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_path(char **avp)
{
	char	**new_path;
	char	*path;
	int		i;

	i = 0;
	while (avp[i])
	{
		if (!ft_strncmp("PATH", avp[i], 4))
			break ;
		else
			++i;
	}
	path = ft_strdup(avp[i]);
	path[3] = '.';
	path[4] = ':';
	new_path = ft_split(path + 3, ':');
	free_mas(&path);
	if (new_path)
		return (new_path);
	return ((void *)0);
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
