/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Damien <dbauduin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 13:48:23 by Damien            #+#    #+#             */
/*   Updated: 2018/05/21 02:08:18 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

t_msh				*ft_newenv(char *env, char *vals)
{
	t_msh		*tmp;

	if (!(tmp = (t_msh *)malloc(sizeof(t_msh))))
		return (0);
	tmp->env = env;
	tmp->vals = vals;
	tmp->next = NULL;
	return (tmp);
}

int					ft_addenv(t_msh **alst, t_msh *new)
{
	if (alst)
		new->next = *alst;
	*alst = new;
	return (1);
}

inline static void	set_shlvl(t_msh *a)
{
	int tmp;

	if (strcmp(a->env, "SHLVL") == 0)
	{
		tmp = ft_atoi(a->vals) + 1;
		free(a->vals);
		a->vals = ft_itoa(tmp);
	}
	else
		set_env(ft_strdup("SHLVL=1"));
}

int					setup(void)
{
	extern char		**environ;
	char			*tmp;
	int				pos;

	pos = -1;
	while (environ[++pos + 1])
		;
	if (!(g_tdin = (t_tdin *)malloc(sizeof(t_tdin))))
		return (0);
	g_msh = ft_newenv(NULL, NULL);
	while (pos >= 0)
	{
		if (environ[pos] && *environ[pos])
		{
			tmp = ft_strdup(environ[pos]);
			g_msh->vals = ft_strdup(ft_strchr(tmp, '=') + 1);
			*(ft_strchr(tmp, '=')) = 0;
			g_msh->env = ft_strdup(tmp);
			free(tmp);
			set_shlvl(g_msh);
		}
		--pos >= 0 ? ft_addenv(&g_msh, ft_newenv(NULL, NULL)) : 0;
	}
	set_env(ft_strdup("SHELL=/Users/damien/42/Minishell/minishell"));
	return (1);
}
