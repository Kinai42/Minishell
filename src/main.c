/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 18:19:22 by dbauduin          #+#    #+#             */
/*   Updated: 2018/04/12 20:29:00 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <unistd.h>
#include <stdio.h>

int	main(int ac, char **av, char **env)
{

	char	**envcpy;
	char	buf[2];
	char	l[2048];
	envcpy = ft_tabcpy(env);

	int i = 0;
	(void)ac;
	if (av)
		i = 0;
	while(envcpy[i])
		printf("%s\n", envcpy[i++]);
	i = 0;
	while(42)
	{
		read(0, buf, 1);
		l[i] = buf[0];
		if (l[i] == '\n')
		{
			printf("%s", l);
			l[i] = 0;
		}
		i++;
	}
	return (0);
}
