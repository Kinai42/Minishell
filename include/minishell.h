/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 08:25:37 by dbauduin          #+#    #+#             */
/*   Updated: 2018/04/27 02:57:43 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/include/libft.h"
# include "../libft/include/printf.h"

# define PROMPT "@>"

typedef struct		s_msh
{
	char			*env;
	char			*vals;
	struct s_msh	*next;
}					t_msh;

t_msh				*g_msh;

typedef struct		s_tdin
{
	char			*line;
	int				pos;
	int				len;
	int				proc;
}					t_tdin;

t_tdin				*g_tdin;

char				*ft_getenv(char *name);
void				ft_stdin();
void				termcaps(char *tc);
void				env(void);
int					prompt(void);
int					setup(void);
int					ft_putc(int c);
int					process_if(void);
t_msh				*ft_newenv(char *env, char *vals);
int					ft_addenv(t_msh **env, t_msh *add);
int					set_env(char *arg);
int					unset_env(char *arg);
void				ft_lstdelelem(t_msh *lst);
void				home(char **str);
void				cd(char *path);
int					execute(char **arg);
void				error(char *msg, char *str);
void				prompt_path(char *path);
int					atoi_s(char *s);
void				ft_escape(char c);
int					ft_flag(char c);
int					ft_putc(int c);
void				ft_lstdelelem(t_msh *lst);

#endif
