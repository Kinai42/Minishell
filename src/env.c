/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Damien <dbauduin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 14:37:30 by Damien            #+#    #+#             */
/*   Updated: 2018/04/14 10:07:18 by Damien           ###   ########.fr       */
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
