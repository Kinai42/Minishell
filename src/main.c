/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 18:19:22 by dbauduin          #+#    #+#             */
/*   Updated: 2018/05/05 01:01:10 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "printf.h"
#include "libft.h"
#include <term.h>
#include <curses.h>
#include <unistd.h>
#include <signal.h>
#include <termios.h>

void	hand(int sig)
{
	int			status;

	if (g_tdin->proc)
	{
		waitpid(g_tdin->proc, &status, 0);
		if (status == 2)
			write(1, "\n", 1);
	}
	else if (sig == 2)
	{
		write(1, "\n", 1);
		free(g_tdin->line);
		g_tdin->line = ft_strnew(0);
		g_tdin->pos = 0;
		g_tdin->len = 0;
		prompt();
	}
}

int		main(void)
{
	char			*name;
	struct termios	term;

	signal(SIGINT, hand);
	if ((setup()) && (name = ft_getenv("TERM")) &&
			tgetent(0, name) && tcgetattr(0, &term) != -1)
	{
		term.c_lflag &= ~(ICANON | ECHO);
		if (tcsetattr(0, TCSANOW, &term) != -1)
			ft_stdin();
	}
	else
		ft_printf("failed to load\n");
	return (0);
}
