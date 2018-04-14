/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 18:19:22 by dbauduin          #+#    #+#             */
/*   Updated: 2018/04/14 10:27:44 by Damien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <term.h>
#include <curses.h>
#include <unistd.h>
#include <signal.h>
#include <termios.h>

void  hand(int sig)
{

	signal(sig, hand);
	write(1, "\n", 1);
	free(g_tdin->line);
	g_tdin->line = ft_strnew(0);
	g_tdin->pos = 0;
	g_tdin->len = 0;
	prompt();

}


int		main(void)
{
	char		*name;
	struct termios	term;

	signal(SIGINT, hand);
	if ((setup()) && (name = ft_getenv("TERM")) && tgetent(0, name) && tcgetattr(0, &term) != -1)
	{
		term.c_lflag &= ~(ICANON | ECHO);
		if (tcsetattr(0, TCSANOW, &term) != -1)
			ft_stdin();
	}
	else
		printf("failed to load");
	return (0);
}

