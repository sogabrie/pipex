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

int	get_here_list(char **av,char **here_doc)
{
	char	*mas2;
	char	*mas3;

	while (1)
	{
		write(1, "heredoc>", 8);
		mas2 = get_next_line(0);
		if (!ft_strcmp_n(av[2], mas2))
			break;
		mas3 = ft_calloc((ft_strlen(*here_doc) + ft_strlen(mas2) + 1), sizeof(char));
		// printf("get_next_4\n");
		if (!mas3)
			return (free_mas(here_doc) || free_mas(&mas2) || 1);
		// printf("get_next_5\n");
		ft_strlcat(mas3, *here_doc, ft_strlen(mas3) + ft_strlen(*here_doc) + 1);
		// printf("get_next_6\n");
		ft_strlcat(mas3, mas2, ft_strlen(mas3) + ft_strlen(mas2) + 1);
		// printf("mas = %s p = %p\n", mas, mas);
		// printf("mas2 = %s p = %p\n", mas2, mas2);
		// printf("mas3 = %s p = %p\n", mas3, mas3);
		// printf("get_next_7\n");
		free_mas(&mas2);
		free_mas(here_doc);
		//printf("get_next_8\n");
		*here_doc = mas3;
	}
	//printf("get_next_14\n");
	free_mas(&mas2);
	//printf("get_next_15\n");
	return (0);
}

int	get_file_list(char *a,char **here_doc)
{
	int		fd;
	int		size;
	char	as;

	fd = open(a, O_RDONLY);
	if (fd < 0)
		return 0;
	size = 0;
	while (0 < read(fd, &as, 1))
		++size;
	*here_doc = ft_calloc(size + 1, sizeof(char));
	if (!(*here_doc))
		return (1);
	close(fd);
	fd = open(a, O_RDONLY);
	if (fd < 0)
		return (free_mas(here_doc));
	if (0 > read(fd, *here_doc, size))
		return (free_mas(here_doc));
	return (1);
}

int	get_first_file(int *ac, char ***av,t_here_doc *first_file)
{
	// printf("av[1] = %s\n", (*av)[1]);
	// printf("strcmp = %d\n", ft_strcmp("here_doc", (*av)[1]));
	if (!ft_strcmp("here_doc", (*av)[1]))
	{
		if (get_here_list(*av, &(first_file->here_doc)))
			return (1);
		*av += 3;
		*ac -= 3;
		first_file->flag = 0;
		return (0);
	}
	if (!get_file_list((*av)[1], &(first_file->here_doc)))
		return (1);
	*av += 2;
	*ac -= 2;
	first_file->flag = 3;
	return (0);
}