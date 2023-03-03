/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_procces_argv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <sogabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:34:33 by sogabrie          #+#    #+#             */
/*   Updated: 2023/03/03 22:37:57 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**creat_proc_args(char *av, char **avp)
{
	char	**pro;

	return (0);
}

int	check_proces_patch(char ****proces, char **av, int ac, char **avp)
{
	int	i;
	char ***proces2;
	
	i = 0;
	while (i < ac)
	{
		proces2 = malloc(sizeof(char **) * (i + 2));
		proces2[i + 1] = 0;
		*proces = cat_proc(proces2, proces);
		proces2 = 0;
		(*proces)[i] = creat_proc_args(av[i], avp);
		if (!(*proces)[i])
			return (1);
		++i;
	}
	return (0);
}