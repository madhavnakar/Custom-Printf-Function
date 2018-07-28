/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_U.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 21:55:28 by mnakar            #+#    #+#             */
/*   Updated: 2018/07/27 21:04:44 by mnakar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	handle_uc(t_info info, va_list *ap)
{
	unsigned long long	n;
	extern int			g_count;
	int					len;
	int					spaces;

	*info.format |= (L);
	n = va_arg(*ap, unsigned long);
	printformat_u(info, n, ULONG, &spaces);
	len = numlen_x(clear_bits_u(n, ULONG), 10);
	g_count += spaces + ((len > info.prec) ? len : info.prec) +
		(ISPOS(info) ? 1 : 0);
}
