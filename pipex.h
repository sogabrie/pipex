/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <sogabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:21:51 by sogabrie          #+#    #+#             */
/*   Updated: 2023/03/07 17:14:37 by sogabrie         ###   ########.fr       */
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
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_here_doc
{
	char	*here_doc;
	int		flag;
}			t_here_doc;

typedef struct s_proces
{
	char	**process;
	char	*proc_path;
	char	**path;
	char	**avp;
}			t_proces;

int		mess_no_args(void);

long	free_mas(char **mas);
long	free_doubl_mas(char ***path);
long	free_triple_mas(char ****mas);

int		get_first_file(int *ac, char ***av, t_here_doc *first_file);

int		creat_proc_args(t_proces *proc, char *av, char **path);

char	**get_path(char **avp);

void	child_parent(t_proces *process, char **avp);

#endif
