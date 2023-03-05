/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_procces_argv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sogabrie <sogabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:34:33 by sogabrie          #+#    #+#             */
/*   Updated: 2023/03/05 20:06:43 by sogabrie         ###   ########.fr       */
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

// int	check_proces_patch(char ****proces, char **av, int ac, char **avp)
// {
// 	int		i;
// 	char	***proces2;
// 	char	**path;


// 	path = get_path(avp);
// 	// (void)proces2;
// 	// (void)ac;
// 	// (void)av;
// 	// (void)proces;
// 	i = 0;
// 	*proces = 0;
// 	while (i < ac - 1)
// 	{
// 		// printf("get_args_5\n");
// 		proces2 = malloc(sizeof(char **) * (i + 2));
// 		if (!proces2)
// 			return (1);
// 		// printf("get_args_6\n");
// 		proces2[i + 1] = 0;
// 		// printf("get_args_7\n");
// 		*proces = cat_proc(&proces2, proces);
// 		// printf("get_args_8\n");
// 		proces2 = 0;
// 		// printf("get_args_9\n");
// 		(*proces)[i] = creat_proc_args(av[i], path);
// 		if (!(*proces)[i])
// 			return (1);
// 		++i;
// 		// printf("get_args_10\n");
// 	}
// 	i = 0;
// 	while (path[i])
// 		printf("path = %s\n", path[i++]);
// 	i = 0;
// 	int j = 0;
// 	while ((*proces)[i])
// 	{
// 		j = 0;
// 		while((*proces)[i][j])
// 			printf("%s ", (*proces)[i][j++]);
// 		printf("\n");
// 		++i;
// 	}
		
// 	free_doubl_mas(&path);
// 	return (0);
// }