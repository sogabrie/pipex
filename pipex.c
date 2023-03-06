/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <sogabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:22:06 by sogabrie          #+#    #+#             */
/*   Updated: 2023/03/06 18:52:52 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	creat_pipe_mas(int ***fd_mas, int i)
{
	int	**mas_2;
	int	*el_1;
	int	j;

	j = -1;
	mas_2 = ft_calloc(i + 1, sizeof(int *));
	el_1 = ft_calloc(2, sizeof(int));
	if (!mas_2 || !el_1)
		return (free_int_mas_2(mas_2, el_1) || 1);
	while (++j <= i)
		mas_2[j] = fd_mas[j];
	mas_2[j] = el_1;
	free_double_int_mas(&fd_mas);
	fd_mas = mas_2;
	return (0);
}

long	pipexs(char **av, t_here_doc *first_file, char **path, int ac)
{
	int		i;
	int	*fd_mas[2];
	t_proces	proces;
	pid_t  pid;
	
	(void)first_file;
	
	i = 0;
	if (creat_pipe_mas(fd_mas, 0))
			return (1);
	pipe(fd_mas[0]);
	while (i < ac - 1)
	{
		creat_proc_args(&proces, av[i],path);
		if (creat_pipe_mas(fd_mas, i + 1))
			return (1);
		pipe(fd_mas[i + 1]);
		pid = fork();
		if (pid < 0)
		 	return (2);
		else if (!pid)
			child_fork(&proces, first_file, fd_mas, i + 1);
		else
		{
			//printf("parent_start\n");
			if (parent_fork(pid, first_file, fd_mas, i + 1))
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