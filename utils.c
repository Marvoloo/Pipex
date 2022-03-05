/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonetta <fdonetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 19:35:21 by fdonetta          #+#    #+#             */
/*   Updated: 2022/03/05 20:07:50 by fdonetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (pid == -1)
	{
		perror("pipex: fork");
		exit(1);
	}
	return (pid);
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
	char	*name;

	if (path == 0 || cmds[0] == 0)
	{
		ft_free(cmds);
		free (path);
		exit (127);
	}
	if (execve(path, cmds, envp) == -1)
	{
		ft_free(cmds);
		free (path);
		name = ft_strdup("execve");
		ft_perror(&name, 1);
	}
}
