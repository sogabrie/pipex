/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_first_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <sogabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:09:11 by sogabrie          #+#    #+#             */
/*   Updated: 2023/03/08 02:58:40 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strcmp_n(char *s2, char *s1)
{
	int	s;

	s = 0;
	while (s1[s] != '\n' && s2[s])
	{
		if (s1[s] > s2[s])
			return (1);
		if (s1[s] < s2[s])
			return (1);
		++s;
	}
	if (s1[s] == '\n' && !s2[s])
		return (0);
	return (1);
}

int	get_here_list(char **av, char **here_doc)
{
	char	*mas2;
	char	*mas3;

	while (1)
	{
		write(1, "heredoc>", 8);
		mas2 = get_next_line(0);
		if (!ft_strcmp_n(av[2], mas2))
			break ;
		mas3 = ft_calloc((ft_strlen(*here_doc) + ft_strlen(mas2) + 1), \
							sizeof(char));
		if (!mas3)
			return (free_mas(here_doc) || free_mas(&mas2) || 1);
		ft_strlcat(mas3, *here_doc, ft_strlen(mas3) + ft_strlen(*here_doc) + 1);
		ft_strlcat(mas3, mas2, ft_strlen(mas3) + ft_strlen(mas2) + 1);
		free_mas(&mas2);
		free_mas(here_doc);
		*here_doc = mas3;
	}
	free_mas(&mas2);
	return (0);
}

int	get_file_list(char *a, char **here_doc)
{
	if (access(a, 0))
		return (1);
	if (access(a, 0))
		return (2);
	*here_doc = ft_strdup(a);
	return (0);
}

long	get_file_name(char **here_doc, char **mas)
{
	int		fd;
	int		i;
	char	file_name[100];

	i = 0;
	file_name[0] = '.';
	while (++i < 100 && !access(file_name, 0))
	{
		file_name[i] = (((i * 48) % 130) + 48) % 130;
		file_name[i + 1] = 0;
	}
	file_name[i] = 0;
	*here_doc = ft_strdup(file_name);
	if (!(*here_doc))
		return (free_mas(mas) || 1);
	fd = open(*here_doc, O_CREAT | O_RDWR, 00777);
	if (fd == -1)
		return (free_mas(mas) || 1);
	i = 0;
	while ((*mas)[i])
		write(fd, &((*mas)[i++]), 1);
	close(fd);
	return (free_mas(mas));
}

int	get_first_file(int *ac, char ***av, t_here_doc *first_file)
{
	char	*mas;
	int		flag;

	mas = 0;
	flag = 0;
	if (!ft_strcmp("here_doc", (*av)[1]))
	{
		if (get_here_list(*av, &mas) || \
				get_file_name(&first_file->here_doc, &mas))
			return (1);
		first_file->flag = 0;
		*av += 3;
		*ac -= 3;
		return (0);
	}
	flag = get_file_list((*av)[1], &first_file->here_doc);
	if (flag)
		return (flag);
	first_file->flag = 3;
	*av += 2;
	*ac -= 2;
	return (0);
}
