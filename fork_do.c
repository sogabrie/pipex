#include "pipex.h"

// int	get_file_fd()

void	child_fork(t_proces *process, t_here_doc *first_file, int **fd, int i, int ac)
{
	// int	i;

	close(fd[i - 1][1]);
	dup2(dup(fd[i-1][0]), 0);
	//printf("ac - 1  = %d i = %d\n", ac - 1, i );
	if (i == ac -1)
	{
		dup2(dup(open("file",  O_CREAT | O_RDWR)), 1);
	}
	else
	{
		dup2(dup(fd[i][1]), 1);
	}
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
	(void)i;

	// int f;

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
	// int t = waitpid(pid, &f, WUNTRACED | WCONTINUED);
	// (void)t;
	// (void)f;
	// printf("\nwait = %d  f = %d\n\n", i, f);
	return (0);
	//exit(EXIT_FAILURE);
}