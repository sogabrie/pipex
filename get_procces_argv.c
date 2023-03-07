/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_procces_argv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <sogabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:34:33 by sogabrie          #+#    #+#             */
/*   Updated: 2023/03/07 15:18:30 by sogabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

long	check_valid_procces(char *mas)
{
	if (!access(mas, 1))
		return (0);
	return (1);
}

long	check_procces(char **pro, char **path, int size, int size_p)
{
	int		i;
	char	*mas;

	i = 0;
	mas = *pro;
	while(path[i])
	{
		if (!check_valid_procces(mas))
		{
			//printf("i = %d\n", i);
			if (!i)
				return (0);
			//printf("mas = %s\n", mas);
			free(*pro);
			*pro = mas;
			return (0);
		}
		if (mas != *pro)
			free(mas);
		size_p = ft_strlen(*pro);
		size = ft_strlen(path[i]);
		mas = ft_calloc(size + size_p + 2, sizeof(char));
		if (!mas)
			return (1);
		ft_strlcat(mas, path[i], size + 1);
		ft_strlcat(mas, "/", size + 2);
		ft_strlcat(mas, *pro, size + size_p + 2);
		++i;
	}
	return (1);	
}

int	creat_proc_args(t_proces *proc, char *av, char **path)
{
	//int		i;
	// char	**pro;
	// char	**pro_2;

	
	proc->process = ft_split(av, ' ');
	proc->proc_path = ft_strdup(proc->process[0]);
	if (!proc->process || !proc->proc_path)
		return (free_doubl_mas(&proc->process) || free_mas(&proc->proc_path));
	if (check_procces((&proc->proc_path), path, 0, 0))
		return (free_doubl_mas(&proc->process) || free_mas(&proc->proc_path));
	// i = 0;
	// while (proc->proc_path[i])
	// 	++i;
	// pro_2 = ft_calloc(i + 2, sizeof(char *));
	// if (!pro_2)
	// 	return ((void *)free_doubl_mas(&pro));
	// i = -1;
	// while (pro[++i])
	// 	pro_2[i] = pro[i];
	// free(pro);
	return (0);
}
