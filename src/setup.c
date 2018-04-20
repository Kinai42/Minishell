/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Damien <dbauduin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 13:48:23 by Damien            #+#    #+#             */
/*   Updated: 2018/04/20 13:22:28 by Damien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <stdlib.h>

t_msh	*ft_newenv(char *env, char *vals)
{
	t_msh	  *tmp;

	if(!(tmp = (t_msh *)malloc(sizeof(t_msh))))
		return(0);
	tmp->env = env;
	tmp->vals = vals;
	tmp->next = NULL;
	return(tmp);
}

int	ft_addenv(t_msh **alst, t_msh *new)
{
	if (alst)
		new->next = *alst;
	*alst = new;
	return(1);
}

int	  setup(void)
{
	extern char		**environ;
	char			*tmp;
	int				pos;

	pos = -1;
	while(environ[++pos + 1]);
	if(!(g_tdin = (t_tdin *)malloc(sizeof(t_tdin))))
		return(0);
	g_msh = ft_newenv(NULL, NULL);
	while(pos >= 0)
	{
		tmp = ft_strdup(environ[pos]);
		if(!(g_msh->vals = ft_strdup(ft_strchr(tmp, '=') + 1)))
			return(0);
		*(ft_strchr(tmp, '=')) = 0;
		if (!(g_msh->env = ft_strdup(tmp)))
			return(0);
		free(tmp);
		if(--pos >= 0)
			ft_addenv(&g_msh, ft_newenv(NULL, NULL));
	}
	set_env(tmp = ft_strdup("_=/usr/bin/env"));
	free(tmp);
	return(1);
}
