/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 02:02:54 by dbauduin          #+#    #+#             */
/*   Updated: 2018/05/09 02:22:53 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*norme(char *tmp, char *arg, char *join)
{
	tmp = ft_strjoin(arg, "/");
	free(arg);
	arg = ft_strjoin(tmp, join);
	free(tmp);
	free(join);
	return (arg);
}
