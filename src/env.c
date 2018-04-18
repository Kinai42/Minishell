/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Damien <dbauduin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 14:37:30 by Damien            #+#    #+#             */
/*   Updated: 2018/04/18 19:16:15 by Damien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env(void)
{
	t_msh	*tmp;

	tmp = g_msh;
	while(tmp)
	{
		ft_putstr(tmp->env);
		write(1, "=", 1);
		ft_putstr(tmp->vals);
		write(1, "\n", 1);
		tmp = tmp->next;
	}
}

int		  set_env(char *arg)
{
	char	*val[2];
	t_msh	*tmp;

	tmp = g_msh;
	if (!arg || !ft_strchr(arg, '='))
		error(arg ? "invalid value" : "invalid name", 0);
	else
	{
		if (!(val[1] = ft_strdup(ft_strchr(arg, '=') + 1)))
			return (0);
		*ft_strchr(arg, '=') = 0;
		val[0] = ft_strdup(arg);
		while (tmp)
		{
			if (!ft_strcmp(tmp->env, val[0]))
			{
				free(tmp->vals);
				tmp->vals = val[1];
				return (1);
			}
			tmp = tmp->next;
		}
		ft_addenv(&g_msh, ft_newenv(val[0], val[1]));
	}
	return (1);
}

int		  unset_env(char *arg)
{
	t_msh	*tmp;
	t_msh	*previous;

	tmp = g_msh;
	previous = tmp;
	if (!arg && printf("ERROR"))
		return(1);
	//		error("bad assignement", 0);
	previous = g_msh;
	if (!ft_strcmp(arg, previous->env))
	{
		g_msh = previous->next;
		free(previous);
		return (1);
	}
	tmp = previous->next;
	while (tmp)
	{
		if (!ft_strcmp(arg, tmp->env))
		{
			previous->next = tmp->next;
			ft_lstdelelem(tmp);
			return (1);
		}
		previous = tmp;
		tmp = tmp->next;
	}
	return (1);
}

char	  *ft_getenv(char *name)
{
	t_msh *tmp;

	tmp = g_msh;
	//	printf("--GETENV--\n");
	while (tmp)
	{
		//		printf("tmp->env = [%s] vs name = [%s]\n", tmp->env, name);
		if (!ft_strcmp(name, tmp->env))
		{
			//			printf("-- GETENV RETURN [%s]\n", tmp->vals);
			return (tmp->vals);
		}
		tmp = tmp->next;
	}
	return (0);
}
