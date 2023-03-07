/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messeg_err.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <sogabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:13:09 by sogabrie          #+#    #+#             */
/*   Updated: 2023/03/07 20:25:24 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	mess_no_args(void)
{
	write (2, "parametrer qich en!\n", 21);
	//system("leaks pipex");
	return (0);
}

int	mess_no_file(char *file, char *fil)
{
	unlink(fil);
	write (2, "zsh: no such file or directory: ", 33);
	write (2, file, ft_strlen(file));
	write (2, "\n", 1);
	//system("leaks pipex");
	return (0);
}

int	mess_error_malloc(char **mas_1, char ***mas_2, char *fil)
{
	unlink(fil);
	free_mas(mas_1);
	free_doubl_mas(mas_2);
	write(2, "malloki sxal\n", 14);
	//system("leaks pipex");
	return (0);
}

int	mess_no_proc(char *file, char *fil, char ***mas, char **mas_2)
{
	free_doubl_mas(mas);
	free_mas(mas_2);
	unlink(fil);
	write (2, "zsh: command not found: ", 25);
	write (2, file, ft_strlen(file));
	write (2, "\n", 1);
	system("leaks pipex");
	exit(2);
	return (0);
}