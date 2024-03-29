/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 03:13:24 by dbauduin          #+#    #+#             */
/*   Updated: 2018/04/27 03:13:29 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>

static int		ft_putwnstr(wchar_t *s, int l)
{
	while (l > 0 && l - (ft_charwlen(*s)) >= 0)
	{
		l -= ft_charwlen(*s);
		ft_putwchar(*s++);
	}
	return (l);
}

static int		ft_wlen(wchar_t *s, int l)
{
	while (l > 0 && l - (ft_charwlen(*s)) >= 0)
		l -= ft_charwlen(*s);
	return (l);
}

static int		ft_out_wch(char s, wchar_t *r, long long *f, int *c)
{
	int l;
	int l2;

	if (!r)
		r = L"(null)";
	l = s == 'c' || s == 'C' ? 1 : ft_strwlen(r);
	l2 = 0;
	while (l--)
		l2 += ft_charwlen(r[l]);
	l2 = (s == 'S' || s == 's') && f[2] >= 0 && f[2] < l2 ? f[2] : l2;
	if (f[1] > l2)
		l2 -= ft_wlen(r, l2);
	l = l2;
	while ((l2 < f[1]) && !(*f >> 2 & 1) && (l2 += 1))
		write(1, *f >> 1 & 1 ? "0" : " ", 1);
	l = ft_putwnstr(r, l);
	if (l > 0)
		l2 -= l;
	while ((l2 < f[1]) && (l2 += 1))
		write(1, " ", 1);
	(*c) += l2;
	return (1);
}

int				ft_cast_wch(char s, va_list ap, long long *f, int *c)
{
	wchar_t		r[2];

	r[1] = L'\0';
	if (s == 'C' || s == 'c')
	{
		*r = va_arg(ap, wint_t);
		return (ft_out_wch(s, r, f, c));
	}
	return (ft_out_wch(s, va_arg(ap, wchar_t*), f, c));
}
