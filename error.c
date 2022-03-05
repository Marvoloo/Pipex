#include "pipex.h"

void	ft_errmsg(char **name, char *str, int a)
{
	int	len;

	write(2, "pipex: ", 7);
	len = ft_strlen(*name);
	write(2, *name, len);
	free(*name);
	write(2, ": ", 2);
	len = ft_strlen(str);
	write(2, str, len);
	if (a > 0)
		exit(a);
}

void	ft_perror(char **name, int a)
{	
	char *str;

	str = ft_strjoin("pipex: ", *name);
	free (*name);
	perror(str);
	free (str);
	if (a > 0)
		exit(a);
}
