/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Damien <dbauduin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 14:37:30 by Damien            #+#    #+#             */
/*   Updated: 2018/04/27 02:05:54 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env(void)
{
	t_msh	*tmp;
	char	*val;

	tmp = g_msh;
	set_env(ft_strdup("_=/Users/damien/42/Minishell/.minishell/env"));
	while (tmp)
	{
		ft_putstr(tmp->env);
		write(1, "=", 1);
		ft_putstr(tmp->vals);
		write(1, "\n", 1);
		tmp = tmp->next;
	}
}

int		set_env(char *arg)
{
	char	*val[2];
	t_msh	*tmp;

	tmp = g_msh;
	if (!arg || !ft_strchr(arg, '='))
		error(arg ? "invalid value" : "invalid name", 0);
	else
	{
		val[1] = ft_strdup(ft_strchr(arg, '=') + 1);
		*ft_strchr(arg, '=') = 0;
		val[0] = ft_strdup(arg);
		free(arg);
		while (tmp)
		{
			if (!ft_strcmp(tmp->env, val[0]))
			{
				free(tmp->vals);
				return ((tmp->vals = val[1]) ? 1 : 0);
			}
			tmp = tmp->next;
		}
		ft_addenv(&g_msh, ft_newenv(val[0], val[1]));
	}
	return (1);
}

int		unset_env(char *arg)
{
	t_msh	*tmp;
	t_msh	*previous;

	previous = g_msh;
	if (!arg)
		error("bad assignement", 0);
	else if (!ft_strcmp(arg, previous->env) && (g_msh = previous->next))
		ft_lstdelelem(previous);
	else
	{
		tmp = previous->next;
		while (tmp)
		{
			if (!ft_strcmp(arg, tmp->env))
			{
				previous->next = tmp->next;
				ft_lstdelelem(tmp);
			}
			previous = tmp;
			tmp = tmp->next;
		}
	}
	return (1);
}

char	*ft_getenv(char *name)
{
	t_msh *tmp;

	tmp = g_msh;
	while (tmp)
	{
		if (!ft_strcmp(name, tmp->env))
			return (tmp->vals);
		tmp = tmp->next;
	}
	return (0);
}
