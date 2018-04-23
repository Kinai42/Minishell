/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Damien <dbauduin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 16:14:08 by Damien            #+#    #+#             */
/*   Updated: 2018/04/23 12:00:53 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <limits.h>

void	cd(char *path)
{
	char	buff[PATH_MAX];
	char	*env;
	char	*tmp;

	if (!path || !ft_strcmp(path, "-"))
		path = path && (*path == '-') ? ft_getenv("OLDPWD") : ft_getenv("HOME");
	if (!path || (chdir(path) == -1))
		return (error("invalid path", path));
	tmp = ft_getenv("PWD");
	if (!(env = ft_strjoin("OLDPWD=", tmp)) || !set_env(env))
		return ;
	free(env);
	if (!(env = ft_strjoin("PWD=", getcwd(buff, PATH_MAX))) || !set_env(env))
		return ;
	free(env);

}
