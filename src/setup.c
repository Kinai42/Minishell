/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Damien <dbauduin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 13:48:23 by Damien            #+#    #+#             */
/*   Updated: 2018/04/14 10:27:07 by Damien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <stdlib.h>

t_msh	*ft_newenv(void)
{
	t_msh	  *tmp;

	if(!(tmp = (t_msh *)malloc(sizeof(t_msh))))
		return(0);
	tmp->env = NULL;
	tmp->vals = NULL;
	tmp->next = NULL;
	return(tmp);
}

void	ft_addenv(t_msh **alst, t_msh *new)
{
	if (alst)
		new->next = *alst;
	*alst = new;
}

int	  setup(void)
{
	extern char **environ;
	char		  *tmp;
	int		  pos;

	pos = 0;
	if(!(g_tdin = (t_tdin *)malloc(sizeof(t_tdin))))
		return(0);
	g_msh = ft_newenv();
	while(environ[pos])
	{
//		printf("--%d--\n", pos);
		tmp = ft_strdup(environ[pos]);
		if(!(g_msh->vals = ft_strdup(ft_strchr(tmp, '=') + 1)))
			return(0);
		*(ft_strchr(tmp, '=')) = 0;
		if (!(g_msh->env = ft_strdup(tmp)))
			return(0);
		free(tmp);
//		printf("env = %s et vals = %s\n", g_msh->env, g_msh->vals);
		if(environ[++pos])
			ft_addenv(&g_msh, ft_newenv());
	}
	return(1);
}
