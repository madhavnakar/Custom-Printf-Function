/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 18:45:10 by mnakar            #+#    #+#             */
/*   Updated: 2018/07/27 21:19:15 by mnakar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	handle_b(t_info info, va_list *ap)
{
	extern int			g_count;
	char				*num;
	unsigned long long	n;

	if (ISHASH(info))
		ft_putstr("0b");
	n = va_arg(*ap, unsigned long long);
	if (!(num = ft_itoa_base(n, 2)))
		return ;
	ft_putstr(num);
	free(num);
	g_count += numlen_x(n, 2) + ((ISHASH(info)) ? 2 : 0);
}
