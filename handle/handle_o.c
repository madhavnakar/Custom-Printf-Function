/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 16:55:15 by mnakar            #+#    #+#             */
/*   Updated: 2018/07/28 14:44:38 by mnakar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

unsigned long long	clear_bits_o(unsigned long long n, int bits)
{
	return ((bits == sizeof(long long) * 8) ? n : ((0x1ull << bits) - 1) & n);
}

int					printhelper_o(t_info info, long long n, t_help help,
					int *spaces)
{
	int		len;
	char	*str;

	len = help.len;
	*spaces = (help.sp > 0) ? help.sp : 0;
	if (ISHASH(info) && help.spchar != ' ' && n != 0)
		ft_putstr("0");
	while (!(ISNEG(info)) && help.sp-- > 0)
		ft_putchar(help.spchar);
	if (ISHASH(info) && help.spchar == ' ' && n != 0)
		ft_putstr("0");
	while (help.len++ < info.prec)
		ft_putchar('0');
	if (!(str = ft_strtolower(ft_itoa_base(n, 8))))
		return (0);
	(n == 0 && !info.prec && !(ISHASH(info))) ? 0 : ft_putstr(str);
	free(str);
	while (help.sp-- > 0)
		ft_putchar(' ');
	return (len);
}

int					printformat_o(t_info info, long long n, int bits,
					int *spaces)
{
	t_help	help;

	help.spchar = ' ';
	help.sp = 0;
	help.len = (!n && !info.prec && !(ISHASH(info))) ? 0 : numlen_x(n, 8);
	if (info.zero && !(ISPER(info)))
	{
		help.sp = info.zero - help.len - (n < 0 || ISPOS(info) ? 1 : 0) -
			(ISHASH(info) ? 1 : 0);
		help.spchar = (ISZERO(info) && n) ? '0' : ' ';
	}
	else if (ISPER(info) || info.zero != 0)
		help.sp = info.zero - ((help.len > info.prec) ? help.len : info.prec) -
			((ISHASH(info) && n) ? 1 : 0);
	help.bits = bits;
	return (printhelper_o(info, n, help, spaces));
}

void				handle_o(t_info info, va_list *ap)
{
	unsigned long long	n;
	size_t				sz;
	extern int			g_count;
	int					len;
	int					spaces;

	sz = UINT;
	if (ISZ(info) && (sz = SIZE_T))
		n = clear_bits_o(va_arg(*ap, size_t), sz);
	else if (ISJ(info) && (sz = UINTMAX_T))
		n = clear_bits_o(va_arg(*ap, intmax_t), sz);
	else if (ISLL(info) && (sz = ULLONG))
		n = clear_bits_o(va_arg(*ap, long long), sz);
	else if (ISL(info) && (sz = ULONG))
		n = clear_bits_o(va_arg(*ap, long), sz);
	else if (ISH(info) && (sz = USHORT))
		n = clear_bits_o(va_arg(*ap, int), sz);
	else if (ISHH(info) && (sz = UCHAR))
		n = clear_bits_o(va_arg(*ap, int), sz);
	else
		n = clear_bits_o(va_arg(*ap, int), sz);
	len = printformat_o(info, n, sz, &spaces);
	g_count += spaces + ((len > info.prec) ? len : info.prec) +
		((ISHASH(info) && clear_bits_o(n, sz)) ? 1 : 0);
}
