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

long	free_mas_ty(char **mas, char **mas2)
{
	//printf("fre_mas_ty_1");
	free_mas(mas);
	//printf("fre_mas_ty_2");
	free_mas(mas2);
	//printf("fre_mas_ty_3");
	return (0);
}