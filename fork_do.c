#include "pipex.h"

void	child_fork(char **process, t_here_doc *first_file, int *fd)
{
	int	i;

	i = 0;
	while (process[i])
		++i;
	process[i] = first_file->here_doc;
	process[i] = "file";
	(void)fd;
	//int j = open("file_2",O_CREAT  | O_WRONLY );
	//dup2(j, dup(1));
	execve(process[0], process, 0);
}

long	parent_fork(pid_t pid, t_here_doc *first_file, int *fd)
{
	printf("parent\n");
	(void)first_file;
	(void)pid;

	int f;

	(void)fd;
	int j = open("file_2", O_CREAT  | O_WRONLY );
	int t = dup(1);
	dup2(j, t);
	// char a;
	// int q = 1;
	// while (q)
	// {
	// 	q = read(j, &a, 1);
	// 	printf("%c",a);
	// }
	int i = wait(&f);
	printf("\nwait = %d  f = %d\n\n", i, f);
	return (0);
	//exit(EXIT_FAILURE);
}