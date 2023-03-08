/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <sogabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:22:06 by sogabrie          #+#    #+#             */
/*   Updated: 2023/03/08 15:23:06 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_file(t_here_doc *first_file, char **av, int ac)
{
	int	file_1;
	int	file_2;

	if (!access(av[ac - 1], 0))
		if (access(av[ac - 1], 2))
			return (2);
	if (first_file->flag)
		file_2 = open(av[ac - 1], O_CREAT | O_WRONLY | O_TRUNC, 00755);
	else
		file_2 = open(av[ac - 1], O_CREAT | O_WRONLY | O_APPEND, 00755);
	file_1 = open(first_file->here_doc, O_RDONLY);
	if (file_1 < 0 || file_2 < 0)
		exit(1);
	dup2(file_1, 0);
	dup2(file_2, 1);
	return (0);
}

int	pipexs(char **av, t_here_doc *first_file, t_proces *proces, int ac)
{
	int	i;

	i = 0;
	if (open_file(first_file, av, ac))
		return (2);
	while (i < ac - 2)
	{
		if (creat_proc_args(proces, &(av[i]), proces->path))
			mess_no_proc(av[i], first_file);
		child_parent(proces, proces->avp);
		if (!first_file->flag)
			unlink(first_file->here_doc);
		free_doubl_mas(&proces->process);
		i++;
	}
	if (creat_proc_args(proces, &(av[i]), proces->path))
	{
		mess_no_proc(av[i], first_file);
		return (1);
	}
	free_doubl_mas(&proces->path);
	execve(proces->proc_path, proces->process, proces->avp);
	return (0);
}

int	main(int ac, char **av, char **avp)
{
	t_here_doc	first_file;
	t_proces	proces;
	int			flag;

	first_file.here_doc = 0;
	proces.proc_path = 0;
	if (ac < 5 || (!ft_strcmp("here_doc", (av)[1]) && ac < 6))
		return (mess_no_args() || 1);
	flag = get_first_file(&ac, &av, &first_file);
	if (flag)
		return (mess_no_file(av[1], &first_file, flag));
	proces.path = get_path(avp);
	proces.avp = avp;
	if (!first_file.here_doc || !proces.path)
		return (mess_error_malloc(&first_file.here_doc, \
		&proces.path, &first_file) || 1);
	if (2 == pipexs(av, &first_file, &proces, ac))
		mess_no_file(av[ac - 1], &first_file, 2);
	if (!first_file.flag)
		unlink(first_file.here_doc);
	free(first_file.here_doc);
	free_doubl_mas(&proces.path);
	return (0);
}
