#include "pipex.h"

void	ft_free(char **array)
{
	int	i;
	
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i ++;
	}
	free(array);
}

int	ft_fork(void)
{
	int	pid;

	pid = fork();
	if (pid == - 1)
	{
		perror("pipex: fork");
		exit(1);
	}
}

void	ft_pipe(int fd[2])
{
	if (pipe(fd) < 0)
	{
		perror("pipex: pipe");
		exit(1);
	}
}

void	ft_process(char **cmds, char *path, char **envp)
{
	if (execve(path, cmds, envp) == -1)
	{
		ft_free(cmds);
		free (path);
		char *name = ft_strdup("error");
		ft_perror(&name, 1);	
	}
}
