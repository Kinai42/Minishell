/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Damien <dbauduin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 16:24:10 by Damien            #+#    #+#             */
/*   Updated: 2018/04/27 14:43:25 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

static char	*ft_homechr(char *arg)
{
	int		i;
	char	*tmp;
	char	*join;

	i = -1;
	while (arg[++i])
	{
		if (arg[i] == '~' && arg[i - 1] != '\\')
		{
			join = ft_strdup(ft_strchr(&arg[i], '~') + 1);
			*ft_strchr(arg, '~') = 0;
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

void		home(char **arg)
{
	char	*tmp;
	int		i;

	i = -1;
	if (!(tmp = ft_getenv("HOME")))
		return ;
	while (arg[++i])
		arg[i] = ft_homechr(arg[i]);
}

void		error(char *msg, char *str)
{
	write(1, "\x1b[31merror\x1b[0m: ", 17);
	write(1, msg, ft_strlen(msg));
	write(1, " \"", 2);
	str ? write(1, str, ft_strlen(str)) : 0;
	write(1, "\"\n", 2);
}

void		prompt_path(char *path)
{
	char	*tmp;

	tmp = NULL;
	if (ft_getenv("HOME") && (tmp = ft_strdup(ft_strstr(path, ft_getenv("HOME") + 1))))
		write(1, "~", 1);
	if (tmp)
	{
		write(1, tmp, ft_strlen(tmp));
		free(tmp);
	}
	else
		write (1, path, ft_strlen(path));
}

int			atoi_s(char *s)
{
	int		ret;
	int		sign;

	ret = -1;
	if (!s)
		return (0);
	while (*s == ' ')
		s++;
	while (s[++ret])
		if (!(s[ret] <= '9' && s[ret] >= '0') && (s[ret] == '-' && !s[ret + 1]))
		{
			write(1, "bash: exit: aa: numeric argument required", 12);
			write(1, s, ft_strlen(s));
			write(1, " numeric argument required", 26);
			return (255);
		}
	ret = 0;
	sign = 1;
	if (*s == '-' && s++)
		sign = -1;
	while (*s && *s >= '0' && *s <= '9')
		ret = ret * 10 + (*s++ - 48);
	return (ret * sign);
}
