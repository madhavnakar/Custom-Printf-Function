/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 09:38:42 by mnakar            #+#    #+#             */
/*   Updated: 2018/07/28 14:44:42 by mnakar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	g_count = 0;
t_table g_table[16] = {{'d', &handle_int}, {'i', &handle_int},
	{'u', &handle_u}, {'s', &handle_s}, {'x', &handle_x}, {'X', &handle_xc},
	{'o', &handle_o}, {'p', &handle_p}, {'c', &handle_c}, {'%', &handle_per},
	{'U', &handle_uc}, {'D', &handle_dc}, {'O', &handle_oc}, {'S', &handle_s},
	{'C', &handle_c}, {'b', &handle_b}};

int	ft_printf(char *s, ...)
{
	va_list		ap;
	extern int	g_count;

	va_start(ap, s);
	while (*s)
	{
		if (*s != '%')
		{
			ft_putchar(*s);
			g_count++;
		}
		else if (*s == '%')
			if (parseopt(&s, &ap) == -1)
				continue ;
		if (!(*s))
			break ;
		s++;
	}
	va_end(ap);
	return (g_count);
}
