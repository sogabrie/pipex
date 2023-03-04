#include "pipex.h"

long	free_mas(char **mas)
{
	// printf("fre_mas_1");
	free(*mas);
	// printf("fre_mas_2");
	*mas = 0;
	// printf("fre_mas_2");
	return (0);
}

long	free_doubl_mas(char ***mas)
{
	int	i;

	i = 0;
	if (!(*mas))
		return (0);
	while ((*mas)[i])
		free_mas(&(*mas)[i++]);
	free(*mas);
	*mas = 0;
	return (0);
}

long	free_triple_mas(char ****mas)
{
	int	i;

	i = 0;
	if (!(*mas))
		return (0);
	while ((*mas)[i])
		free_doubl_mas(&(*mas)[i++]);
	free(*mas);
	*mas = 0;
	return (0);
}