/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 14:19:01 by mnakar            #+#    #+#             */
/*   Updated: 2018/07/28 10:22:01 by mnakar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

unsigned long long	clear_bits_u(unsigned long long n, int bits)
{
	return ((bits == LLONG) ? n : ((0x1ull << bits) - 1) & n);
}

void				ft_putunum(unsigned long long n)
{
	if (n <= 9)
		ft_putchar(n + '0');
	else
	{
		ft_putunum(n / 10);
		ft_putchar((n % 10) + '0');
	}
}

void				printformat_u(t_info info, unsigned long long n,
					int bits, int *spaces)
{
	int			sp;
	char		spchar;
	int			len;

	n = clear_bits_u(n, bits);
	spchar = ' ';
	sp = 0;
	len = numlen_x(n, 10);
	if (info.zero && !(ISPER(info)))
	{
		sp = info.zero - len - (ISPOS(info) ? 1 : 0);
		spchar = ISZERO(info) ? '0' : ' ';
	}
	else if (ISPER(info))
		sp = info.zero - ((len > info.prec) ? len : info.prec);
	*spaces = (sp > 0) ? sp : 0;
	while (!(ISNEG(info)) && sp-- > 0)
		ft_putchar(spchar);
	while (len++ < info.prec)
		ft_putchar('0');
	ft_putunum(n);
	while (sp-- > 0)
		ft_putchar(' ');
}

void				handle_u(t_info info, va_list *ap)
{
	unsigned long long	n;
	size_t				sz;
	extern int			g_count;
	int					len;
	int					spaces;

	sz = sizeof(unsigned int) * 8;
	if (*info.format & 0x2000000 && (sz = sizeof(unsigned char) * 8))
		n = va_arg(*ap, int);
	else if (*info.format & 0x1000000 && (sz = sizeof(unsigned short) * 8))
		n = va_arg(*ap, int);
	else if (*info.format & 0x800000 && (sz = sizeof(unsigned long) * 8))
		n = va_arg(*ap, long);
	else if (*info.format & 0x400000 && (sz = sizeof(unsigned long long) * 8))
		n = va_arg(*ap, long long);
	else if (*info.format & 0x200000 && (sz = sizeof(uintmax_t) * 8))
		n = va_arg(*ap, intmax_t);
	else if (*info.format & 0x100000 && (sz = sizeof(size_t) * 8))
		n = va_arg(*ap, size_t);
	else
		n = va_arg(*ap, int);
	printformat_u(info, n, sz, &spaces);
	len = numlen_x(clear_bits_u(n, sz), 10);
	g_count += spaces + ((len > info.prec) ? len : info.prec);
}
