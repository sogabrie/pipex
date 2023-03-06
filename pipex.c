/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <sogabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:22:06 by sogabrie          #+#    #+#             */
/*   Updated: 2023/03/06 21:10:33 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	creat_pipe_mas(int ***fd_mas, int i)
{
	int	**mas_2;
	int	*el_1;
	int	j;

	j = -1;
	//  printf("creat_pipe_1\n");
	mas_2 = ft_calloc(i + 1, sizeof(int *));
	// printf("creat_pipe_2\n");
	el_1 = ft_calloc(2, sizeof(int));
	// printf("creat_pipe_3\n");
	if (!mas_2 || !el_1)
		return (1);
		//return (free_int_mas_2(mas_2, el_1) || 1);
	// printf("creat_pipe_4\n");
	while (++j < i)
		mas_2[j] = (*fd_mas)[j];
	// printf("creat_pipe_5\n");
	mas_2[j] = el_1;
	//free_double_int_mas(fd_mas);
	*fd_mas = mas_2;
	// printf("fd_mas[0][0] = %d\n", *fd_mas[0][0]);
	return (0);
}

long	pipexs(char **av, t_here_doc *first_file, char **path, int ac, char **avp)
{
	int		i;
	// int	**fd_mas;
	t_proces	proces;
	// pid_t  pid;
	(void)first_file;
	// (void)first_file;
	
	// i = 0;
	// if (creat_pipe_mas(&fd_mas, 0))
	// 		return (1);
	// // printf("Pipexs_5\n");
	// pipe(fd_mas[0]);
	// // printf("Pipexs_6\n");
	// dup2(fd_mas[0][0], dup(open("file_2",O_RDWR)));
	// // printf("Pipexs_7\n");
	i = 0;
	int file_1 = open("file", O_RDONLY);
	int file_2 = open("file_2", O_CREAT | O_WRONLY | O_TRUNC, 00777);
	dup2(file_1, 0);
	dup2(file_2, 1);
	// creat_proc_args(&proces, av[0],path);
	// child_parent(&proces, avp, 1);
	while (i < ac - 2)
	{
		creat_proc_args(&proces, av[i++],path);
		child_parent(&proces, avp);
	}
	creat_proc_args(&proces, av[i],path);
	execve(proces.proc_path, proces.process, avp);

	// while (i < ac - 1)
	// {
	// 	// printf("Pipexs_8\n");
	// 	creat_proc_args(&proces, av[i],path);
	// 	// printf("Pipexs_9\n");
	// 	// if (creat_pipe_mas(&fd_mas, i + 1))
	// 	// 	return (1);
	// 	// printf("Pipexs_10\n");
	// 	// pipe(fd_mas[i + 1]);

	// 	int pip[2];
	// 	pipe(pip);
	// 	pid_t pid = fork();
	// 	if (pid < 0)
	// 	 	return (2);
	// 	else if (pid)
	// 		parent_fork(pid, first_file, pip, i + 1);
	// 	else
	// 	{
	// 		//printf("parent_start\n");
	// 		child_fork(&proces, first_file, pip, i + 1 , ac, avp);
	// 	}
	// 	++i;
	// }
	// unlink(first_file->here_doc);
	// close(fd_mas[0][0]);
	// close(fd_mas[i][1]);
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
	if (pipexs(av, &first_file, path, ac, avp))
		return (0);
	// proces = creat_proc_args(av[0],path);
	
	free(first_file.here_doc);
	free_doubl_mas(&path);
	//system("leaks pipex");
	return (0);
}