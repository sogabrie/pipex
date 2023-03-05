/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <sogabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:22:06 by sogabrie          #+#    #+#             */
/*   Updated: 2023/03/05 21:16:48 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

long	pipexs(char **av, t_here_doc *first_file, char **path, int ac)
{
	int		i;
	t_proces	proces;
	pid_t  pid;
	(void)first_file;
	
	i = 0;
	while (i < ac - 1)
	{
		printf("aaaaaaaaaaaaaaaaa\n");
		creat_proc_args(&proces, av[i],path);
		int j = 0;
		while (proces.process && proces.process[j])
			printf("proces = %s\n", proces.process[j++]);
		printf("proc_path = %s\n", proces.proc_path);
		int fd[2];
		pipe(fd);
		pid = fork();
		if (pid < 0)
		 	return (2);
		else if (!pid)
			child_fork(&proces, first_file, fd);
		else
		{
			//printf("parent_start\n");
			if (parent_fork(pid, first_file, fd))
				return (3);
		}
		++i;
	}
	//return (write_file(here_doc, av));
	return (0);
}

int	main(int ac, char **av, char **avp)
{
	t_here_doc	first_file;
	char		**path;

	first_file.here_doc = 0;
	if (ac < 4)
		return (mess_no_args() || 1);
	//printf("main_4\n");
	get_first_file(&ac, &av, &first_file);
	//printf("main_5\n");
	path = get_path(avp);
	//printf("main_6\n");
	if (!first_file.here_doc || !path)
		return (0);
	//printf("main_7\n");
	if (pipexs(av, &first_file, path, ac))
		return (0);
	// proces = creat_proc_args(av[0],path);
	
	free(first_file.here_doc);
	free_doubl_mas(&path);
	//system("leaks pipex");
	return (0);
}