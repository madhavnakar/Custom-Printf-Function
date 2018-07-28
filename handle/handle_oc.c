/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_O.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 21:55:28 by mnakar            #+#    #+#             */
/*   Updated: 2018/07/27 21:02:36 by mnakar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	handle_oc(t_info info, va_list *ap)
{
	unsigned long long	n;
	extern int			g_count;
	int					len;
	int					spaces;
	int					numlen;

	*info.format |= (L);
	n = va_arg(*ap, unsigned long);
	printformat_o(info, n, ULONG, &spaces);
	numlen = numlen_x(clear_bits_o(n, ULONG), 8);
	len = (!clear_bits_o(n, ULONG) && !info.prec) ? 0 : numlen;
	g_count += spaces + ((len > info.prec) ? len : info.prec) +
		(ISHASH(info) ? 1 : 0);
}
