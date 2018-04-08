/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 16:30:17 by dbauduin          #+#    #+#             */
/*   Updated: 2017/10/21 16:30:19 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			*ss;

	i = -1u;
	ss = (char *)s;
	while (ss[++i])
		if (ss[i] == (char)c)
			return (ss + i);
	if (ss[i] == (char)c)
		return (ss + i);
	return (NULL);
}
