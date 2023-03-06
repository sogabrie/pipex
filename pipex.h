/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <sogabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:21:51 by sogabrie          #+#    #+#             */
/*   Updated: 2023/03/06 19:53:06 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <string.h>
# include <errno.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <sys/types.h>
# include "libft.h"
#include <sys/types.h>
#include <sys/wait.h>

typedef struct s_here_doc
{
	char	*here_doc;
	int		flag;
}			t_here_doc;

typedef struct s_proces
{
	char	**process;
	char	*proc_path;
}			t_proces;

int		mess_no_args();

long	free_mas(char **mas);
long	free_doubl_mas(char ***path);
long	free_triple_mas(char ****mas);
long	free_int_mas_2(int	**mas_2,int *el_1);
long	free_mas_int(int **mas);
long	free_double_int_mas(int ***mas);

int		get_first_file(int *ac, char ***av,t_here_doc *first_file);

// int		check_proces_patch(char ****proces, char **av, int ac, char **avp);
int		creat_proc_args(t_proces *proc, char *av, char **path);

//char	***cat_proc(char ****proces2, char ****proces);
char	**get_path(char **avp);

void	child_parent(t_proces *process, char **avp, int i);
void	child_fork(t_proces *process, t_here_doc *first_file, int *fd, int i, int ca, char **avp);
long	parent_fork(pid_t pid, t_here_doc *first_file, int *fd, int i);

#endif
