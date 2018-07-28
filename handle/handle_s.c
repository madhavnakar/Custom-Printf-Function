/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 14:11:16 by mnakar            #+#    #+#             */
/*   Updated: 2018/07/27 21:14:54 by mnakar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	handle_s(t_info info, va_list *ap)
{
	char		*s;
	int			fill_z;
	extern int	g_count;

	s = va_arg(*ap, char *);
	if (!s)
		s = "(null)";
	if (info.prec == -1)
		fill_z = info.zero - ft_strlen(s);
	else if (info.prec < (int)ft_strlen(s))
		fill_z = info.zero - info.prec;
	else
		fill_z = info.zero - ft_strlen(s);
	g_count += ((fill_z < 0) ? 0 : fill_z) + ((info.prec != -1 &&
				info.prec < (int)ft_strlen(s)) ? info.prec : ft_strlen(s));
	while (!(ISNEG(info)) && fill_z-- > 0)
		(ISZERO(info)) ? ft_putchar('0') : ft_putchar(' ');
	while (*s && (info.prec || !(ISPER(info))))
	{
		ft_putchar(*s);
		s++;
		info.prec--;
	}
	while (ISNEG(info) && fill_z-- > 0)
		ft_putchar(' ');
}
