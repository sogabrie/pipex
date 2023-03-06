#include "pipex.h"

// int	get_file_fd()

void	child_fork(t_proces *process, t_here_doc *first_file, int *fd, int i, int ac, char **avp)
{
	//if (i == 0)

	(void)first_file;
	(void)i;
	(void)ac;
	printf("child\n");
	if (i == ac -1)
	{
		exit(1);
		close(fd[0]);
		dup2(open("file_2", O_CREAT | O_WRONLY | O_TRUNC), 1);
	}
	else
	{
		close(fd[0]);
		dup2(fd[1], 1);
	}

	execve(process->proc_path, process->process, avp);

	// close(fd[i - 1][1]);
	// dup2(dup(fd[i-1][0]), 0);
	// printf("ac - 1  = %d i = %d\n", ac - 1, i );
	// if (i == ac -1)
	// {
	// 	//int ftt = open("file",  O_CREAT | O_RDWR);
	// 	dup2(dup(open("file",  O_CREAT | O_RDWR)), 1);
	// }
	// else
	// {
	// 	dup2(dup(fd[i][1]), 1);
	// }
	// // i = 0;
	// // while (process[i])
	// // 	++i;
	// // process[i] = first_file->here_doc;
	// (void)fd;
	// (void)first_file;
	// //int j = open("file_2",O_CREAT  | O_WRONLY );
	// //dup2(j, dup(1));
	// execve(process->proc_path, process->process, 0);
}

long	parent_fork(pid_t pid, t_here_doc *first_file, int *fd, int i)
{
	(void)first_file;
	(void)i;

	close(fd[1]);
	dup2(fd[0], 0);
	waitpid(pid, NULL, 0);
	// // printf("parent\n");
	// (void)first_file;
	// (void)pid;
	// (void)i;

	// // int f;

	// (void)fd;
	// // int j = open("file_2", O_CREAT  | O_WRONLY );
	// // int t = dup(1);
	// // dup2(j, t);
	// // char a;
	// // int q = 1;
	// // while (q)
	// // {
	// // 	q = read(j, &a, 1);
	// // 	printf("%c",a);
	// // }
	// // printf("parent_10\n");
	// //int t = waitpid(pid, &f, WUNTRACED | WCONTINUED);
	// // (void)t;
	// // (void)f;
	// // printf("wait = %d  f = %d\n", t, f);
	return (0);
	// //exit(EXIT_FAILURE);
}

void	child_parent(t_proces *process, char **avp)
{
	pid_t	pid;
	int		fd[2];

	pipe(fd);
	pid = fork();
	if (pid)
	{
		close(fd[1]);
		dup2(fd[0], 0);
		waitpid(pid, NULL, 0);
	}
	else
	{
		close(fd[0]);
		dup2(fd[1], 1);
		execve(process->proc_path, process->process, avp);
	}
}