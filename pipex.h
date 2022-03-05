/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonetta <fdonetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 20:14:29 by fdonetta          #+#    #+#             */
/*   Updated: 2022/03/05 21:54:11 by fdonetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "get_next_line.h"

typedef struct s_pid {
	int		pid;
}	t_pid;

int		ft_fork(void);
void	ft_free(char **array);
void	ft_pipe(int fd[2]);
void	ft_perror(char **name, int a);
void	ft_errmsg(char **name, char *str, int a);
void	ft_process(char **cmds, char *path, char **envp);
char	*ft_getpath(char **cmds, char **envp, int errno);
char	**ft_check_cmds(char **cmds);
char	**ft_join(char **str, int a, int b, int len);
int		ft_remdqoutes(char **str, int *flag);

int		ft_check_heredoc(int argc, char **argv, int *out);

#endif