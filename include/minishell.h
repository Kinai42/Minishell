/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 08:25:37 by dbauduin          #+#    #+#             */
/*   Updated: 2018/04/14 10:22:09 by Damien           ###   ########.fr       */
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
}				t_tdin;

t_tdin			  *g_tdin;

char	*ft_getenv(char *name); //recherche name dans lenvironnement;
t_msh	*ft_newenv(void); // crée un nouveau maillon;
void	ft_stdin(void); // Read;
void	termcaps(char *tc); //action command fleche, backspace, ctrl+l, ctrl+d
void	env(void); //print environnement
int		prompt(void); //affiche le PROMPT
int		setup(void); // crée la liste chainée;
int		ft_putc(int c); 
int		process_if(void); //recherche l'executable et mise en arg

