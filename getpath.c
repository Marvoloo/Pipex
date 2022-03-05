#include "pipex.h"

char	*ft_getcpath(char *cmd)
{
	char	*path;

	path = ft_strdup(cmd);
	if (access(path, F_OK) == 0)
		return (path);
	return (0);	
}

char	**ft_splitenvp(char **envp)
{
	char 	**str;
	int		i;

	i = 0;
	str = 0;
	if (envp[i] == 0)
		str = ft_split("/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin:/sbin", ':');
	else
	{
		while (envp[i] && ft_strnstr(envp[i], "PATH=", 5) == 0)
			i ++;
		str = ft_split(envp[i] + 5, ':');
	}
	return (str);
}

char	*ft_getepath(char *cmd, char **envp)
{
	char 	**str;
	char	*tmp;
	char	*path;
	int		i;

	i = 0;
	str = ft_splitenvp(envp);
	while (str[i])
	{	
		tmp = ft_strjoin(str[i], "/");
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(path, F_OK) == 0)
		{
			ft_free(str);
			return (path);
		}
		free(path);
		i ++;
	}
	ft_free(str);
	return (0);
}

int		ft_checkfile(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '/')
		{
			// while (str[++ i])
			// {
			// 	if (str[i] != '/')
					return (1);
			// }
			// return (2);
		}
		i ++;
	}
	return (0);
}

char	*ft_getpath(char **cmds, char **envp, int err)
{
	char	*path;
	char	*name;
	int		flag;

	flag = ft_checkfile(cmds[0]);
	if (flag == 1)
		path = ft_getcpath(cmds[0]);
	else if (flag == 0)	
		path = ft_getepath(cmds[0], envp);
	if (path == 0)
	{	
		name = ft_strdup(cmds[0]);
		// ft_free(cmds);
		// free (path);
		if (flag == 1)
			ft_perror(&name, err);
		// else if (flag == 2)	
		// 	ft_errmsg(&name, "not a directory\n", err);
		else	
			ft_errmsg(&name, "command not found\n", err);	
	}
	return (path);
}
