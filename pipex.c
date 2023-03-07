/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <sogabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:22:06 by sogabrie          #+#    #+#             */
/*   Updated: 2023/03/07 15:37:34 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

long	pipexs(char **av, char *first_file, t_proces *proces, int ac)
{
	int	i;

	i = 0;
	int file_1 = open(first_file, O_RDONLY);
	int file_2 = open(av[ac - 1], O_CREAT | O_WRONLY | O_TRUNC, 00755);
	if (file_1 < 0 || file_2 < 0)
		return (1);
	dup2(file_1, 0);
	dup2(file_2, 1);
	while (i < ac - 2)
	{
		creat_proc_args(proces, av[i++],proces->path);
		child_parent(proces, proces->avp);
		unlink(first_file);
	}
	creat_proc_args(proces, av[i],proces->path);
	system("leaks pipex");
	execve(proces->proc_path, proces->process, proces->avp);
	return (0);
}

int	main(int ac, char **av, char **avp)
{
	char	*first_file;
	t_proces	proces;

	first_file = 0;
	if (ac < 4)
		return (mess_no_args() || 1);
	//printf("main_4\n");
	get_first_file(&ac, &av, &first_file);
	//printf("main_5\n");
	proces.path = get_path(avp);
	proces.avp = avp;
	//printf("main_6\n");
	if (!first_file || !proces.path)
		return (0);
	//printf("main_7\n");
	if (pipexs(av, first_file, &proces, ac))
		return (0);
	// proces = creat_proc_args(av[0],path);
	
	free(first_file);
	free_doubl_mas(&proces.path);
	system("leaks pipex");
	return (0);
}