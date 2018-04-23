/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 08:25:37 by dbauduin          #+#    #+#             */
/*   Updated: 2018/04/23 12:57:51 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"
#include "../libft/include/printf.h"

# define PROMPT "@>"


typedef struct		s_msh
{
	char			*env;
	char			*vals;
	struct	s_msh	*next;
}				t_msh;

t_msh				*g_msh;

typedef struct		s_tdin
{
	char  *line;
	int	  pos;
	int	  len;
	int	  proc;
}				t_tdin;

t_tdin			  *g_tdin;

char	*ft_getenv(char *name); //recherche name dans lenvironnement;
void	ft_stdin(); // Read;
void	termcaps(char *tc); //action command fleche, backspace, ctrl+l, ctrl+d
void	env(void); //print environnement
int		prompt(void); //affiche le PROMPT
int		setup(void); // crée la liste chainée;
int		ft_putc(int c); 
int		process_if(void); //recherche l'executable et mise en arg
t_msh	*ft_newenv(char *env, char *vals);
int		ft_addenv(t_msh **env, t_msh *add);
int		set_env(char *arg);
int		unset_env(char *arg);
void	ft_lstdelelem(t_msh *lst);
void	home(char **);
void	cd(char *path);
int		execute(char **arg);
void	error(char *msg, char *str);
void	prompt_path(char *path);
int	atoi_s(char *s);

