/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 21:13:57 by mnakar            #+#    #+#             */
/*   Updated: 2018/07/28 18:29:41 by mnakar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	printformat_p(t_info info, long long n, int bits, int *spaces)
{
	int		sp;
	int		len;
	char	*str;

	sp = 0;
	bits++;
	len = numlen_x(n, 16);
	ft_putstr("0x");
	if (info.zero && !(ISPER(info)))
		sp = info.zero - len - (ISPOS(info) ? 1 : 0) - ((ISHASH(info)) ? 2 : 0);
	else if (ISPER(info))
		sp = info.zero - ((len > info.prec) ? len : info.prec) -
			(ISHASH(info) ? 2 : 0);
	*spaces = sp;
	while ((!(ISNEG(info)) && sp-- > 0))
		ft_putchar(ISZERO(info) ? '0' : ' ');
	while (len++ < info.prec)
		ft_putchar('0');
	if (!(str = ft_strtolower(ft_itoa_base(n, 16))))
		return ;
	ft_putstr(str);
	free(str);
	while (sp-- > 0)
		ft_putchar(' ');
}

void	handle_p(t_info info, va_list *ap)
{
	unsigned long long	n;
	size_t				sz;
	extern int			g_count;
	int					len;
	int					spaces;

	n = va_arg(*ap, unsigned long);
	sz = sizeof(char *) * 8;
	printformat_p(info, n, sz, &spaces);
	len = numlen_x(n, 16);
	g_count += spaces + ((len > info.prec) ? len : info.prec) + 2;
}
