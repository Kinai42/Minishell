/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Damien <dbauduin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 14:28:38 by Damien            #+#    #+#             */
/*   Updated: 2018/04/27 02:39:00 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>
#include <unistd.h>
#include <term.h>
#include <limits.h>

int			prompt(void)
{
	char	*user;
	char	*path;
	char	buff[PATH_MAX];

	user = ft_getenv("USER");
	if (!(path = ft_strjoin("PWD=", getcwd(buff, PATH_MAX))) || !set_env(path))
		return (0);
	path = ft_getenv("PWD");
	write(1, user, strlen(user));
	write(1, "\033[32m", 5);
	write(1, " ", 1);
	prompt_path(path);
	write(1, "\033[0m", 4);
	write(1, "> ", 2);
	return (1);
}

static int	exec(void)
{
	write(1, "\n", 1);
	if (*g_tdin->line && !process_if())
		return (0);
	free(g_tdin->line);
	g_tdin->line = ft_strnew(0);
	g_tdin->pos = 0;
	g_tdin->len = 0;
	prompt();
	return (1);
}

static char	*ft_addbuffposx(char *buff)
{
	char	*tmp;
	char	*join;

	if (!(join = ft_strdup(&g_tdin->line[g_tdin->pos])))
		return (0);
	g_tdin->line[g_tdin->pos] = 0;
	tmp = ft_strdup(g_tdin->line);
	free(g_tdin->line);
	g_tdin->line = ft_strjoin(tmp, buff);
	free(tmp);
	tmp = ft_strjoin(g_tdin->line, join);
	free(join);
	return (tmp);
}

static int	addbuff(char *buff)
{
	char	*tmp;
	int		i;

	if (g_tdin->pos < g_tdin->len)
		tmp = ft_addbuffposx(buff);
	else if (!(tmp = ft_strjoin(g_tdin->line, buff)))
		return (0);
	i = ft_strlen(&tmp[g_tdin->pos]);
	write(1, &tmp[g_tdin->pos], i);
	i -= ft_strlen(buff) - 1;
	while (--i > 0)
		write(1, "\b", 1);
	free(g_tdin->line);
	g_tdin->line = tmp;
	g_tdin->len = ft_strlen(g_tdin->line);
	g_tdin->pos += ft_strlen(buff);
	return (1);
}

void		ft_stdin(void)
{
	char	buff[4];
	int		rd;

	g_tdin->line = ft_strnew(0);
	g_tdin->pos = 0;
	g_tdin->len = 0;
	g_tdin->proc = 0;
	prompt();
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
