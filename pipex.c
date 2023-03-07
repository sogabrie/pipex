/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <sogabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:22:06 by sogabrie          #+#    #+#             */
/*   Updated: 2023/03/07 17:39:53 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

long	pipexs(char **av, t_here_doc *first_file, t_proces *proces, int ac)
{
	int	i;
	int	file_1;
	int	file_2;

	i = 0;
	if (first_file->flag)
		file_2 = open(av[ac - 1], O_CREAT | O_WRONLY | O_TRUNC, 00755);
	else
		file_2 = open(av[ac - 1], O_CREAT | O_WRONLY | O_APPEND, 00755);
	file_1 = open(first_file->here_doc, O_RDONLY);
	if (file_1 < 0 || file_2 < 0)
		return (6);
	dup2(file_1, 0);
	dup2(file_2, 1);
	while (i < ac - 2)
	{
		creat_proc_args(proces, av[i++], proces->path);
		child_parent(proces, proces->avp);
		unlink(first_file->here_doc);
	}
	creat_proc_args(proces, av[i], proces->path);
	//system("leaks pipex");
	execve(proces->proc_path, proces->process, proces->avp);
	return (0);
}

int	main(int ac, char **av, char **avp)
{
	t_here_doc	first_file;
	t_proces	proces;

	first_file.here_doc = 0;
	proces.proc_path = 0;
	if (ac < 4)
		return (mess_no_args() || 1);
	get_first_file(&ac, &av, &first_file);
	proces.path = get_path(avp);
	proces.avp = avp;
	if (!first_file.here_doc || !proces.path)
		return (0);
	if (pipexs(av, &first_file, &proces, ac))
		return (0);
	free(first_file.here_doc);
	free_doubl_mas(&proces.path);
	//system("leaks pipex");
	return (0);
}
