/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_D.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 21:55:28 by mnakar            #+#    #+#             */
/*   Updated: 2018/07/27 20:58:15 by mnakar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	handle_dc(t_info info, va_list *ap)
{
	unsigned long long	n;
	extern int			g_count;
	int					len;
	int					spaces;
	int					numlen;

	*info.format |= (L);
	n = va_arg(*ap, unsigned long);
	printformat_int(info, n, ULONG, &spaces);
	numlen = ft_numlen((isneg(n, ULONG, 0) ? negate(n, ULONG) : n), 10);
	len = (!n && !info.prec) ? 0 : numlen;
	g_count += spaces + ((len > info.prec) ? len : info.prec) +
		((ISPOS(info) || isneg(n, ULONG, 1) || ISSP(info)) ? 1 : 0);
}
