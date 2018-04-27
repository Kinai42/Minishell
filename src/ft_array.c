/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 03:43:43 by dbauduin          #+#    #+#             */
/*   Updated: 2018/04/27 03:47:50 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>
#include <term.h>
#include <curses.h>
#include <termios.h>

void	ft_echo(char **arg)
{
	int		i;
	int		j;

	i = 0;
	while (arg[i])
	{
		j = 0;
		while (arg[i][j])
		{
			if (arg[i][j] == '\\' && ft_flag(arg[i][++j]))
			{
				if (arg[i][j] == 'c')
					return ;
				ft_escape(arg[i][j]);
			}
			else if (arg[i][j])
				write(1, &arg[i][j], 1);
			j++;
		}
		if (arg[++i])
			write(1, " ", 1);
	}
	write(1, "\n", 1);
}

int		ft_count(char *str)
{
	int		count;
	char	quote;

	count = 0;
	while (*str)
	{
		quote = '\0';
		while (*str && *str == ' ')
			str++;
		if (*str && *str != ' ')
		{
			count++;
			while (*str && *str != ' ')
			{
				if (*str == '"' || *str == '\'')
				{
					!quote ? quote = *(str++) : 0;
					while (*str && *str != quote)
						str++;
				}
				*str ? str++ : 0;
			}
		}
	}
	return (count);
}

char	*ft_word(char **s)
{
	char	*word;
	char	quote;

	if (!(word = malloc(sizeof(char))))
		return (0);
	*word = '\0';
	quote = '\0';
	while (**s && **s != ' ')
	{
		if (**s == '"' || **s == '\'')
		{
			if (!quote)
				quote = *((*s)++);
			while (**s && **s != quote)
			{
				if (**s == '~')
					word = ft_addchar(word, '\\');
				word = ft_addchar(word, *((*s)++));
			}
		}
		else if (**s != '\\' || (**s == '\\' && *(*s - 1) == '\\'))
			word = ft_addchar(word, **s);
		**s ? *s += 1 : 0;
	}
	return (word);
}

char	**split(char *str)
{
	char	**array;
	char	*word;
	int		count;

	count = ft_count(str);
	if (!(array = (char **)malloc(sizeof(char*) * (count + 1))))
		return (0);
	array[count] = NULL;
	count = 0;
	while (*str)
	{
		while (*str && *str == ' ')
			str++;
		if (*str)
		{
			if (!(word = ft_word(&str)))
				return (0);
			array[count++] = strdup(word);
			free(word);
		}
	}
	return (array);
}

int		process_if(void)
{
	char	**arg;

	arg = split(g_tdin->line);
	home(arg);
	if (!ft_strcmp(*arg, "echo"))
		ft_echo(&arg[1]);
	else if (!ft_strcmp(*arg, "env"))
		env();
	else if (!ft_strcmp(*arg, "setenv"))
		set_env(ft_strdup(arg[1]));
	else if (!ft_strcmp(*arg, "unsetenv"))
		unset_env(arg[1]);
	else if (!ft_strcmp(*arg, "cd"))
		cd(arg[1]);
	else if ((!ft_strcmp(*arg, "exit") && write(1, "exit\n", 5))
			|| !execute(arg))
		exit(!ft_strcmp(*arg, "exit") ? (atoi_s(arg[1])) : (0));
	ft_cleaner(arg);
	return (1);
}
