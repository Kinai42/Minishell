/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Damien <dbauduin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 18:18:34 by Damien            #+#    #+#             */
/*   Updated: 2018/04/27 02:41:30 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>

static void	exec_error(int id)
{
	if (id == 6)
		printf("{red}error{eoc} > process terminated [ABRT]\n");
	else if (id == 8)
		printf("{red}error{eoc} > process terminated [FPE]\n");
	else if (id == 10)
		printf("{red}error{eoc} > process terminated [BUSERR]\n");
	else if (id == 11)
		printf("{red}error{eoc} > process terminated [SEGV]\n");
}

static char	*check_path(char *path, char *name)
{
	char	*tmp;
	char	*dir;

	if (!(dir = ft_strjoin(path, "/")) ||
			!(tmp = ft_strjoin(dir, name)))
		return (0);
	free(dir);
	if (access(tmp, X_OK) != -1)
		return (tmp);
	free(tmp);
	return (0);
}

static char	*find_path(char *name)
{
	char	**paths;
	int		i;
	char	*tmp;
	char	*path;

	i = 0;
	if (!(tmp = ft_getenv("PATH")))
		return (ft_strdup(name));
	if (!(paths = ft_strsplit(tmp, ':')))
		return (0);
	path = 0;
	while (paths[i])
	{
		!path ? path = check_path(paths[i], name) : 0;
		free(paths[i++]);
	}
	free(paths);
	return (path ? path : ft_strdup(name));
}

static char	**tabenv(void)
{
	char	**tab;
	t_msh	*tmp;
	char	*env;
	int		i;

	i = 0;
	tmp = g_msh;
	while (tmp && ++i)
		tmp = tmp->next;
	if (!(tab = malloc(sizeof(char*) * (i + 1))))
		return (0);
	tab[i] = 0;
	tmp = g_msh;
	i = 0;
	while (tmp)
	{
		env = ft_strjoin(tmp->env, "=");
		tab[i++] = ft_strjoin(env, tmp->vals);
		free(env);
		tmp = tmp->next;
	}
	return (tab);
}

int			execute(char **args)
{
	pid_t	childp;
	int		status;
	char	*path;

	if (!(path = find_path(*args)))
		return (1);
	childp = fork();
	g_tdin->proc = childp;
	if (childp < 0)
		error("fork failed", 0);
	else if (childp == 0)
	{
		execve(path, args, tabenv());
		error("command not found", *args);
		free(path);
		return (0);
	}
	else
	{
		wait(&status);
		exec_error(status);
	}
	g_tdin->proc = 0;
	free(path);
	return (1);
}
