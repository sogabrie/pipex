/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messeg_err.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <sogabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:13:09 by sogabrie          #+#    #+#             */
/*   Updated: 2023/03/08 15:05:57 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	mess_no_args(void)
{
	write (2, "Please give more arguments\n", 28);
	return (0);
}

int	mess_no_file(char *file, t_here_doc *fil, int flag)
{
	if (flag == 1)
	{
		write (2, "zsh: no such file or directory: ", 33);
		write (2, file, ft_strlen(file));
	}
	else
	{
		if (!fil->flag)
			unlink(fil->here_doc);
		write (2, "zsh: permission denied: ", 25);
		write (2, file, ft_strlen(file));
	}
	return (2);
}

int	mess_error_malloc(char **mas_1, char ***mas_2, t_here_doc *file)
{
	if (!file->flag)
		unlink(file->here_doc);
	free_mas(mas_1);
	free_doubl_mas(mas_2);
	write(2, "ERROR malloc\n", 14);
	return (0);
}

int	mess_no_proc(char *file, t_here_doc *fil)
{
	if (!fil->flag)
		unlink(fil->here_doc);
	write (2, "zsh: command not found: ", 25);
	write (2, file, ft_strlen(file));
	write (2, "\n", 1);
	exit(0);
	return (0);
}
