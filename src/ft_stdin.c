/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Damien <dbauduin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 14:28:38 by Damien            #+#    #+#             */
/*   Updated: 2018/04/14 10:02:14 by Damien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <stdlib.h>
#include <unistd.h>
#include <term.h>

int	  prompt(void)
{
	char	*user;
	char	*patch;

	user = ft_getenv("USER");
	patch = ft_getenv("PWD");
	write(1, user, strlen(user));
	write(1, "\033[32m", 5);
	write(1," ", 1);
	write(1, patch, strlen(patch));
	write(1, "> ", 2);
	write(1, "\033[0m", 4);
	return(1);
}

static int	  exec(void)
{
	printf("\n--EXEC-- \n[%s] -- [%d] -- [%d]\n", g_tdin->line, g_tdin->pos, g_tdin->len);
	if (*g_tdin->line && !process_if()) // execution du programme mis en **arg et choix du programme
		return (0);
	free(g_tdin->line);
	g_tdin->line = ft_strnew(0);
	g_tdin->pos = 0;
	g_tdin->len = 0;
	prompt();
	return (1);
}

static int	  addbuff(char *buff)
{
	char	*tmp;
	int	  i;

	if (g_tdin->pos < g_tdin->len)
	{
		if (!(tmp = ft_strndup(g_tdin->line, ft_strlen(g_tdin->line) + 1)))
			return (0);
		tmp[g_tdin->pos] = *buff;
		ft_strcpy(&tmp[g_tdin->pos + 1], &g_tdin->line[g_tdin->pos]);
	}
	else if (!(tmp = ft_strjoin(g_tdin->line, buff)))
		return (0);
	i = ft_strlen(&tmp[g_tdin->pos]);
	write(1, &tmp[g_tdin->pos], i);
	while (--i)
		write(1, "\b", 1);
	free(g_tdin->line);
	g_tdin->line = tmp;
	g_tdin->len++;
	g_tdin->pos++;
	return (1);
}

void	  ft_stdin(void)
{
	char	buff[4];
	int	  rd;

	g_tdin->line = ft_strnew(0);
	g_tdin->pos = 0;
	g_tdin->len = 0;
	prompt();
//	printf("-- FT_STDIN --\n");
	while ((rd = read(0, buff, 3)))
	{
		buff[rd] = 0;
		if (*buff == '\n' && !exec())
			return ;
		else if (*buff < 32 || *buff == 127)
			termcaps(ft_strdup(buff));
		else if (*buff > 31 && !addbuff(buff))
			return ;
	}
}
