/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 16:27:16 by dbauduin          #+#    #+#             */
/*   Updated: 2017/10/21 16:27:19 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(long long n)
{
	char				*s;
	int					i;
	long long			k;

	k = n;
	s = ft_strnew(ft_intlen(n));
	if (s == NULL)
		return (NULL);
	i = (k < 0) ? ft_intlen(k) : ft_intlen(k) - 1;
	if (k < 0)
	{
		s[0] = '-';
		i--;
		k *= -1;
	}
	else if (k == 0)
		s[0] = '0';
	while (k > 0)
	{
		s[i] = (k % 10) + 48;
		k /= 10;
		i--;
	}
	return (s);
}
