#include "pipex.h"

int	ft_finddqoutes(char **str, char c, int *a, int *flag)
{	
	int	i;

	i = *a;
	while((*str)[++ (*a)])
	{
		if ((*str)[(*a)] == c)
		{
			(*a) ++;
			return (0);
		}	
	} 
	if (c == '\"')
		*flag = 1;
	if (c == 39)
		*flag = 2;
	return (1);
}

int	ft_findsecqoutes(char **str, int *flag)
{
	int	i;

	i = 0;
	while((*str)[i])
	{
		if ((*str)[i] == '\"' && (*flag == 1 || *flag == -1))	
			return (1);
		else if ((*str)[i] == 39 && (*flag == 2 || *flag == -1))
			return (1);
		else 
			i ++;		
	}
	return (0);
}

int ft_findqoutes(char **str, int *flag)
{
	int	i;
	int	count;

	i = count = 0;
	while((*str)[i])
	{
		if ((*str)[i] == '\\')
		{
			i ++;
			while ((*str)[i] == 39)
				i ++;
		}
		else if ((*str)[i] == '\"' && (*flag == 1 || *flag == -1))	
			count = ft_finddqoutes(str, '\"', &i, flag);
		else if ((*str)[i] == 39 && (*flag == 2 || *flag == -1))
			count = ft_finddqoutes(str, 39, &i, flag);
		else 
			i ++;		
	}
	return (count);
}

char **ft_check_cmds(char **cmds)
{
	int	i;
	int	a;
	int flag;

	i = a = flag = -1;	
	while (cmds[++ i])
	{	
		if (a == -1)
		{
			if (ft_findqoutes(&cmds[i], &flag))
				a = i;
		}
		else if (ft_findsecqoutes(&cmds[i], &flag))
		{
			cmds = ft_join(cmds, a, i, 0);
			i = a - 1;
			a = flag = -1;
		}
	}
	i = a = flag = -1;	
	while (cmds[++ i])	
		ft_remdqoutes(&cmds[i], &flag);
	return (cmds);
}