/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 08:59:48 by dbauduin          #+#    #+#             */
/*   Updated: 2018/03/24 09:00:22 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void			prompt(void)
{
	char	*user;

	(user = fetchenv("USER")) ? ft_printf("{green}%s{eoc} >> ", user) :
		ft_printf("{green}%s{eoc} >> ", PROMPT);
}
