/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Damien <dbauduin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 17:56:27 by Damien            #+#    #+#             */
/*   Updated: 2018/04/14 10:07:55 by Damien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>

void	  echo(char **arg)
{
	while (*arg)
	{
		write(1, *arg, ft_strlen(*arg));
		if (*(++arg))
			write(1, " ", 1);
	}
	write(1, "\n", 1);
}

int		ft_count(char *str)
{
	int		count;
	char	quote;

	count = 0;
	quote = '\0';
	while (*str)
	{
//		printf("FIRST str = [%s]\n", str);
		while (*str && *str == ' ')
			str++;
		while (*str && *str != ' ')
		{
			if (*str == '"' || *str == '\'')
			{
				if(!quote)
					quote = *(str++);
				while (*str && *str != quote)
				{
//					printf("*STR = [%c]\n", *str);
					str++;
				}
			}
//			printf("LAST str = [%s]\n", str);
			*str ? str++ : 0;
		}
		count++;
		quote = '\0';
//		printf("COUNT = [%d]\n", count);

	}
	return(count);
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
			if(!quote)
				quote = *((*s)++);
			while (**s && **s != quote)
				word = ft_addchar(word, *((*s)++));
		}
		else
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
//	printf("COUNT WORD = %d\n", count);
	if(!(array = (char **)malloc(sizeof(char*) * (count + 1))))
		return(0);
	array[count] = NULL;
	count = 0;
	while(*str)
	{
//		printf("CHAR S = %d\n", *str);
		while(*str && *str == ' ' && *str++);
		if(*str)
		{
			if(!(word = ft_word(&str)))
				return (0);
//			printf("WORD = [%s]\n", word);
			array[count++] = strdup(word);
			free(word);
		}
//		printf("STR = %s\n", str);
	}
	return(array);
}


int		  process_if(void)
{
	char	**arg;
//	int i =0;
	arg = split(g_tdin->line);
//	while(arg[i])
//		printf("%s\n", arg[i++]);
	if (!ft_strcmp(*arg, "echo"))
		echo(&arg[1]);
		else if (!ft_strcmp(*arg, "env"))
			env();
	else if (!ft_strcmp(*arg, "exit"))
		exit (0);
	ft_cleaner(arg);
	return (1);
}
