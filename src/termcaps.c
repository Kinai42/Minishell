/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Damien <dbauduin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 16:13:55 by Damien            #+#    #+#             */
/*   Updated: 2018/04/27 02:28:47 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>
#include <term.h>

static void		move(char c)
{
	if (c == 'D' && g_tdin->pos)
	{
		write(1, "\b", 1);
		g_tdin->pos--;
	}
	else if (c == 'C' && g_tdin->pos < g_tdin->len)
	{
		write(1, &g_tdin->line[g_tdin->pos], 1);
		g_tdin->pos++;
	}
}

static void		backspace(void)
{
	int i;

	move('D');
	tputs(tgetstr("dc", 0), 1, ft_putc);
	ft_strcpy(&g_tdin->line[g_tdin->pos], &g_tdin->line[g_tdin->pos + 1]);
	g_tdin->len--;
	i = ft_strlen(&g_tdin->line[g_tdin->pos]);
	while (i-- >= 0)
		write(1, "1", 1);
	i = ft_strlen(&g_tdin->line[g_tdin->pos]);
	while (i-- >= 0 && write(1, "\b", 1))
		tputs(tgetstr("dc", 0), 1, ft_putc);
	i = ft_strlen(&g_tdin->line[g_tdin->pos]);
	write(1, &g_tdin->line[g_tdin->pos], i);
	i = g_tdin->len - g_tdin->pos + 1;
	while (--i > 0)
		write(1, "\b", 1);
}

static void		clear(void)
{
	tputs(tgetstr("cl", 0), 0, ft_putc);
	prompt();
	write(1, g_tdin->line, g_tdin->len);
}

void			termcaps(char *tc)
{
	if (!tc)
		return ;
	if (*tc == 4)
	{
		write(1, "exit\n", 5);
		exit(0);
	}
	*tc == 127 && g_tdin->pos ? backspace() : 0;
	*tc == 27 ? move(tc[2]) : 0;
	*tc == 12 ? clear() : 0;
	free(tc);
}
