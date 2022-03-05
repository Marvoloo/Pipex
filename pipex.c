#include "pipex.h"

void	ft_read(int in, char *argv, char **envp)
{
	int		fd[2];
	int		pid;
	char	*path;
	char	**cmds;

	ft_pipe(fd);
	if (in >= 0)
	{	
		cmds = ft_split(argv, ' ');
		cmds = ft_check_cmds(cmds);	
		path = ft_getpath(cmds, envp, 0);
		pid = ft_fork();
		if (pid == 0)
		{	
			if (path == 0)
				exit(0);
			close(fd[0]);
			dup2(fd[1], 1);
			ft_process(cmds, path, envp);
		}
		ft_free(cmds);
		free(path);
	}
	close(fd[1]);
	dup2(fd[0], 0);
	close(fd[0]);
}

void	ft_write(int out, char *argv, char **envp)
{
	char	*path;
	char	**cmds;

	cmds = ft_split(argv, ' ');
	cmds = ft_check_cmds(cmds);
	path = ft_getpath(cmds, envp, 0);
	if (path != 0)
	{
		dup2(out, 1);
		ft_process(cmds, path, envp);
	}
	ft_free(cmds);
	free(path);
}

void	ft_openfile(int *fd, int i, char *file)
{
	char	*name;

	if (i == 0)
		*fd = open(file, O_RDONLY, 0664);
	if (i == 1)
	{
		*fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0664);
		if (*fd <= 0)
		{
			name = ft_strdup(file);
			ft_perror(&name, 1);
		}
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	int		in;
	int		out;
	char	*name;

	if (argc == 5)
	{	
		ft_openfile(&in, 0, argv[1]);
		ft_openfile(&out, 1, argv[4]);
		if (in < 0)
		{	
			name = ft_strdup(argv[1]);
			ft_perror(&name, 0);
		}
		else
			dup2(in, 0);
		ft_read(in, argv[2], envp);
		ft_write(out, argv[3], envp);
	}
	else
		write (2, "pipex: bad arguments\n", 22);
	return (0);
}
