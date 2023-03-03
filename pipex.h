/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <sogabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:21:51 by sogabrie          #+#    #+#             */
/*   Updated: 2023/03/04 00:02:41 by sogabrie         ###   ########.fr       */
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

int	mess_no_args();

long	free_mas(char **mas);
long	free_mas_ty(char **mas, char **mas2);

int		get_first_file(int *ac, char ***av, char **here_doc);

#endif
