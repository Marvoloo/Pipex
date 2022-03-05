#include "pipex.h"

void	ft_catcmd(char **cmds, char *cmd)
{
	char *str;
	char *tmp;

	tmp = ft_strjoin(*cmds, " ");
	str = ft_strjoin(tmp, cmd);
	free(tmp);
	free(*cmds);
	*cmds = str;
}

char	**ft_join(char **str, int a, int b, int len)
{
	char *tmp;
	char *tmp_1;
	char **ret;
	int	i;

	i = -1;
	while (str[len ++]);
	ret = (char **) malloc (sizeof(char *) * (len - (b - a - 1)));
	if (!ret)
		return (str);
	while (++ i < a)
		ret[i] = ft_strdup(str[i]);
	ret[i] = ft_strdup(str[a]);
	while (++ a <= b)
		ft_catcmd(&ret[i], str[a]);
	i ++;
	while (str[a])
		ret[i ++] = ft_strdup(str[a ++]);
	ft_free(str);
	return (ret); 
}
