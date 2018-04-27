/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 02:58:46 by dbauduin          #+#    #+#             */
/*   Updated: 2018/04/27 03:00:49 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabcpy(char **tab)
{
	char	**tabcpy;
	int		count;
	int		i;

	count = ft_counttab(tab);
	i = -1;
	if (!(tabcpy = malloc(sizeof(char *) * count + 1)))
		return (0);
	tab[count] = NULL;
	while (++i < count - 1)
		tabcpy[i] = ft_strdup(tab[i]);
	return (tabcpy);
}
