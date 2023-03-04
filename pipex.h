/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <sogabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:21:51 by sogabrie          #+#    #+#             */
/*   Updated: 2023/03/04 23:58:29 by sogabrie         ###   ########.fr       */
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

int		mess_no_args();

long	free_mas(char **mas);
long	free_doubl_mas(char ***path);
long	free_triple_mas(char ****mas);

int		get_first_file(int *ac, char ***av, char **here_doc);

int		check_proces_patch(char ****proces, char **av, int ac, char **avp);

char	***cat_proc(char ****proces2, char ****proces);
char	**get_path(char **avp);

#endif
