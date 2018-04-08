/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 08:25:37 by dbauduin          #+#    #+#             */
/*   Updated: 2018/04/08 03:07:59 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"

# define SIZE 27


typedef struct		s_msh
{
	char			**env;
	char			**vals;
}				t_msh;

t_msh				*g_msh;

char	**history;
