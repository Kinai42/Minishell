/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Damien <dbauduin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 16:24:10 by Damien            #+#    #+#             */
/*   Updated: 2018/04/18 20:20:52 by Damien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <stdlib.h>

int		ft_putc(int c)
{
	write(1, &c, 1);
	return (c);
}

void	ft_lstdelelem(t_msh *lst)
{
	free(lst->env);
	free(lst->vals);
	free(lst);
}

static char	*ft_homechr(char *arg)
{
	int		i;
	char	*tmp;
	char	*join;

	i = -1;
	while(arg[++i])
	{
		if(arg[i] == '~' && arg[i - 1] != '\\')
		{
			if (!(join = ft_strdup(ft_strchr(&arg[i], '~') + 1)))
				return(0);
			*ft_strchr(arg, '~' ) = 0;
			tmp = ft_strdup(arg);
			free(arg);
			arg = ft_strjoin(arg, ft_getenv("HOME"));
			free(tmp);
			if (*join)
			{
				tmp = ft_strjoin(arg, "/");
				free(arg);
				arg = ft_strjoin(tmp, join);
				free(tmp);
			}
		}
	}
	return (arg);
}

void	  home(char **arg)
{
	char	*tmp;
	int		i;

	i = -1;
	if (!(tmp = ft_getenv("HOME")))
		return ;
	while (arg[++i])
	{
		arg[i] = ft_homechr(arg[i]);
	}
}

void	error(char *msg, char *str)
{
	write(1, "\x1b[31merror\x1b[0m: ", 17);
	write(1, msg, ft_strlen(msg));
	write(1, " \"", 2);
	str ? write(1, str, ft_strlen(str)) : 0;
	write(1, "\"\n", 2);
}

void	prompt_path(char *path)
{
	char	*tmp;
	
	if((tmp = ft_strdup(ft_strstr(path, ft_getenv("HOME") + 1))))
		write(1, "~", 1);
	write(1, tmp, ft_strlen(tmp));
	free(tmp);
}
