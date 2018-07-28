/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 14:09:57 by mnakar            #+#    #+#             */
/*   Updated: 2018/07/28 14:31:38 by mnakar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putnum(long long n, int bits)
{
	if (bits == INT)
		ft_putnbr((int)n);
	else if (bits == SHORT)
		ft_putshort((short)n);
	else if (bits == SCHAR)
		ft_putschar((signed char)n);
	else if (bits == LONG || bits == INTMAX_T)
		ft_putlong((long)n);
	else if (bits == LLONG)
		ft_putlonglong((long long)n);
}

int		printhelper_int(t_info info, long long n, t_help help, int *spaces)
{
	long long	put_n;
	int			len;

	len = help.len;
	*spaces = (help.sp > 0) ? help.sp : 0;
	while (help.spchar == ' ' && !(ISNEG(info)) && help.sp-- > 0)
		ft_putchar(help.spchar);
	if (ISPOS(info) || isneg(n, help.bits, 0))
		(isneg(n, help.bits, 0)) ? ft_putchar('-') : ft_putchar('+');
	while (help.spchar == '0' && !(ISNEG(info)) && help.sp-- > 0)
		ft_putchar(help.spchar);
	while (help.len++ < info.prec)
		ft_putchar('0');
	put_n = isneg(n, help.bits, 0) ? -n : n;
	(!n && !info.prec) ? 0 : ft_putnum(put_n, help.bits);
	while (help.sp-- > 0)
		ft_putchar(' ');
	return (len);
}

int		printformat_int(t_info info, long long n, int bits, int *spaces)
{
	t_help		help;
	long long	put_n;

	put_n = isneg(n, bits, 0) ? negate(n, bits) : n;
	help.spchar = ' ';
	help.sp = 0;
	help.len = (!n && !info.prec) ? 0 : ft_numlen(put_n, 10);
	if (ISSP(info) && !(ISPOS(info)) && !isneg(n, bits, 0))
	{
		info.zero--;
		ft_putchar(' ');
	}
	if (info.zero && !(ISPER(info)))
	{
		help.sp = info.zero - help.len - ((isneg(n, bits, 0) ||
					ISPOS(info) ? 1 : 0));
		help.spchar = (ISZERO(info)) ? '0' : ' ';
	}
	else if (ISPER(info))
		help.sp = info.zero - ((help.len > info.prec) ? help.len : info.prec) -
			((isneg(n, bits, 0) || ISPOS(info) ? 1 : 0));
	help.bits = bits;
	return (printhelper_int(info, n, help, spaces));
}

void	handle_int(t_info info, va_list *ap)
{
	long long	n;
	size_t		sz;
	int			spaces;
	int			len;
	extern int	g_count;

	sz = INT;
	if (ISZ(info) && (sz = SIZE_T))
		n = clear_bits(va_arg(*ap, size_t), sz);
	else if (ISJ(info) && (sz = INTMAX_T))
		n = clear_bits(va_arg(*ap, intmax_t), sz);
	else if (ISLL(info) && (sz = LLONG))
		n = clear_bits(va_arg(*ap, long long), sz);
	else if (ISL(info) && (sz = LONG))
		n = clear_bits(va_arg(*ap, long), sz);
	else if (ISH(info) && (sz = SHORT))
		n = clear_bits(va_arg(*ap, int), sz);
	else if (ISHH(info) && (sz = SCHAR))
		n = clear_bits(va_arg(*ap, int), sz);
	else
		n = clear_bits(va_arg(*ap, int), sz);
	len = printformat_int(info, (long)n, sz, &spaces);
	g_count += spaces + ((len > info.prec) ? len : info.prec) +
		((ISPOS(info) || isneg(n, sz, 1) || ISSP(info)) ? 1 : 0);
}
