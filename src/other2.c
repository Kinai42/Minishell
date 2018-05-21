/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 02:42:17 by dbauduin          #+#    #+#             */
/*   Updated: 2018/05/21 02:15:35 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>
#include <unistd.h>

int			echo_env(char *name)
{
	t_msh	*tmp;

	tmp = g_msh;
	if (strlen(name) == 1 && name[0] == '$')
		write(1, "$", 1);
	name++;
	while (tmp)
	{
		if (!ft_strcmp(name, tmp->env))
		{
			write(1, tmp->vals, ft_strlen(tmp->vals));
			return (0);
		}
		tmp = tmp->next;
	}
	return (0);
}

int			ft_putc(int c)
{
	write(1, &c, 1);
	return (c);
}

void		ft_lstdelelem(t_msh *lst)
{
	free(lst->env);
	free(lst->vals);
	free(lst);
}

void		ft_escape(char c)
{
	if (c == '0')
		write(1, "\0", 1);
	if (c == 'a')
		write(1, "\a", 1);
	if (c == 'b')
		write(1, "\b", 1);
	if (c == 'f')
		write(1, "\f", 1);
	if (c == 'n')
		write(1, "\n", 1);
	if (c == 'r')
		write(1, "\r", 1);
	if (c == 't')
		write(1, "\t", 1);
}

int			ft_flag(char c)
{
	if (c == '0' || c == 'a' || c == 'b' || c == 'f' || c == 'n' ||\
			c == 'r' || c == 't' || c == 'c')
		return (1);
	return (0);
}
