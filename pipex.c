/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonetta <fdonetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 20:08:02 by fdonetta          #+#    #+#             */
/*   Updated: 2022/03/05 22:44:07 by fdonetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_read(int in, char *argv, char **envp, int *fd)
{
	// int		fd[2];
	char	*path;
	char	**cmds;
	int		pid;

	// ft_pipe(fd);
	if (in >= 0)
	{	
		cmds = ft_check_cmds(ft_split(argv, ' '));
		path = ft_getpath(cmds, envp, 0);
		pid = ft_fork();
		if (pid == 0)
		{	
			close(fd[0]);
			dup2(in, 0);
			dup2(fd[1], 1);
			ft_process(cmds, path, envp);
		}
		ft_free(cmds);
		free(path);
	}
	// close(fd[0]);
	// close(fd[1]);
	// close(fd[1]);
	// dup2(fd[0], 0);
	// close(fd[0]);
}

void	ft_write(int out, char *argv, char **envp, int *fd)
{
	char	*path;
	char	**cmds;
	int		pid;
	
	cmds = ft_check_cmds(ft_split(argv, ' '));
	path = ft_getpath(cmds, envp, 127);
	pid = ft_fork();
	if (pid == 0)
	{	
		close(fd[1]); 
		dup2(out, 1);
		dup2(fd[0], 0);
		ft_process(cmds, path, envp);
	}
	ft_free(cmds);
	free(path);
	// close(fd[0]);
	// close(fd[1]);
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
	int		fd[2];
	
	if (argc == 5)
	{	
		ft_openfile(&in, 0, argv[1]);
		ft_openfile(&out, 1, argv[4]);
		if (in < 0)
		{	
			name = ft_strdup(argv[1]);
			ft_perror(&name, 0);
		}
		ft_pipe(fd);
		ft_read(in, argv[2], envp, fd);
		ft_write(out, argv[3], envp, fd);
		close(fd[0]);
		close(fd[1]);
		waitpid(-1, 0, 0);
		waitpid(-1, 0, 0);
	}
	else
	{
		write (2, "pipex: bad arguments\n", 22);
		exit (127);
	}
	return (0);
}

// (p1 p2) p3 -> fork() if !pid -> ft_execute() else: while (argc-- -4)
 //															waitpid(pid, NULL, 0);


 