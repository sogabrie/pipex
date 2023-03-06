#include "pipex.h"

// int	get_file_fd()

void	child_fork(t_proces *process, t_here_doc *first_file, int **fd, int i)
{
	// int	i;

	// i = 0;
	// while (process[i])
	// 	++i;
	// process[i] = first_file->here_doc;
	(void)fd;
	(void)first_file;
	//int j = open("file_2",O_CREAT  | O_WRONLY );
	//dup2(j, dup(1));
	execve(process->proc_path, process->process, 0);
}

long	parent_fork(pid_t pid, t_here_doc *first_file, int **fd, int i)
{
	// printf("parent\n");
	(void)first_file;
	(void)pid;

	int f;

	(void)fd;
	// int j = open("file_2", O_CREAT  | O_WRONLY );
	// int t = dup(1);
	// dup2(j, t);
	// char a;
	// int q = 1;
	// while (q)
	// {
	// 	q = read(j, &a, 1);
	// 	printf("%c",a);
	// }
	// int i = wait(&f);
	// printf("\nwait = %d  f = %d\n\n", i, f);
	return (0);
	//exit(EXIT_FAILURE);
}