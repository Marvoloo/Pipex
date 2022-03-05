/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonetta <fdonetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 19:38:08 by fdonetta          #+#    #+#             */
/*   Updated: 2022/03/05 19:38:20 by fdonetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_stdread(int fd, char *lim)
{
	char	*line;

	while (get_next_line(&line))
	{
		if (ft_strncmp(lim, line, ft_strlen(lim) + 1) == 0)
		{
			free (line);
			close(fd);
			exit (0);
		}
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free (line);
	}
}

void	ft_bonus(int argc, char *lim)
{
	int		fd[2];
	int		pid;

	if (argc < 6 && lim == 0)
	{
		write (2, "pipex: bad arguments\n", 22);
		exit (1);
	}
	ft_pipe(fd);
	pid = ft_fork();
	if (pid == 0)
	{
		close(fd[0]);
		ft_stdread(fd[1], lim);
	}
	else
	{
		wait (0);
		close(fd[1]);
		dup2(fd[0], 0);
		close(fd[0]);
	}
}

int	ft_check_heredoc(int argc, char **argv, int *out)
{
	char	*name;

	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
	{
		*out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0664);
		if (*out < 0)
		{
			name = ft_strdup(argv[argc - 1]);
			ft_perror(&name, 1);
		}
		ft_bonus(argc, argv[2]);
		return (3);
	}
	return (2);
}
