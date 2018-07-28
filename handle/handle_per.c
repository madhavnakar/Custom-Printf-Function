/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_%.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 19:38:48 by mnakar            #+#    #+#             */
/*   Updated: 2018/07/27 21:17:48 by mnakar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	handle_per(t_info info, va_list *ap)
{
	int			fill_z;
	extern int	g_count;
	int			warning;

	if (ap)
		warning = 0;
	fill_z = info.zero - 1;
	g_count += ((fill_z > 0) ? fill_z : 0) + 1;
	while (!(ISNEG(info)) && fill_z-- > 0)
		ISZERO(info) ? ft_putchar('0') : ft_putchar(' ');
	ft_putchar('%');
	while (ISNEG(info) && fill_z-- > 0)
		ft_putchar(' ');
}
