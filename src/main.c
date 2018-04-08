/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 18:19:22 by dbauduin          #+#    #+#             */
/*   Updated: 2018/04/08 05:11:30 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <unistd.h>
#include <stdio.h>

int	main(int ac, char **av, char **env)
{

	char	**envcpy;

	envcpy = ft_tabcpy(env);

	int i = 0;
	(void)ac;
	if (av)
	i = 0;
	while(envcpy[i])
		printf("%s\n", envcpy[i++]);
	chdir("/Users/damien");
	printf("user=Damien\n");
	return (0);
}
