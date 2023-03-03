/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <sogabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:22:06 by sogabrie          #+#    #+#             */
/*   Updated: 2023/03/04 00:58:32 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **avp)
{
	char	***proces;
	char	*here_doc;
	
	(void)avp;
	(void)proces;
	here_doc = 0;
	if (ac < 4)
		return (mess_no_args() || 1);
	get_first_file(&ac, &av, &here_doc);
	// if (!here_doc || check_proces_patch(&proces, av, ac, avp))
	// 	return (free_ret(&proces, &here_doc));
	printf("%s", here_doc);
	free(here_doc);
	system("leaks pipex");
	return (0);
}