/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 14:11:16 by mnakar            #+#    #+#             */
/*   Updated: 2018/07/27 21:11:35 by mnakar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	handle_c(t_info info, va_list *ap)
{
	char		s;
	int			fill_z;
	extern int	g_count;

	s = va_arg(*ap, int);
	fill_z = info.zero - 1;
	g_count += ((fill_z > 0) ? fill_z : 0) + 1;
	while (!(ISNEG(info)) && fill_z-- > 0)
		(ISZERO(info)) ? ft_putchar('0') : ft_putchar(' ');
	ft_putchar(s);
	while (ISNEG(info) && fill_z-- > 0)
		ft_putchar(' ');
}
