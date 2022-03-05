#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "get_next_line.h"

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