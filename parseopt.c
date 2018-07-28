/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseopt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 12:40:23 by mnakar            #+#    #+#             */
/*   Updated: 2018/07/27 20:41:34 by mnakar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parseflags(char **s, int *format)
{
	int	fill;
	int sp_appeared;

	fill = 0;
	sp_appeared = *format & SP;
	while (isflag(**s) || ft_isdigit(**s))
	{
		if (**s == '-')
			*format |= NEG;
		else if (**s == '+')
			*format |= POS;
		else if (**s == ' ')
			*format |= SP;
		else if (**s == '0')
			*format |= ZERO;
		else if (**s == '#')
			*format |= HASH;
		else if (ft_isdigit(**s))
		{
			fill = ft_atoi_mover(s);
			(*s)--;
		}
		(*s)++;
	}
	return ((*format & SP && !fill && !sp_appeared) ? 1 : fill);
}

int	parsefield(char **s, int *format)
{
	int a;

	a = 1;
	if (**s == 'h')
		a = (*(++(*s)) == 'h') ? !(*format |= (HH)) : !(*format |= (H));
	else if (**s == 'l')
		a = (*(++(*s)) == 'l') ? !(*format |= (LL)) : !(*format |= (L));
	else if (**s == 'j')
		*format |= (J);
	else if (**s == 'z')
		*format |= (Z);
	if (isfield(**s))
		(*s)++;
	return (1);
}

int	parseprecision(char **s, int *format)
{
	int max;

	max = -1;
	if (**s == '.')
	{
		(*s)++;
		*format |= (PER);
		max = ft_atoi(*s);
		while (ft_isdigit(**s))
			(*s)++;
	}
	return (max);
}

int	parseconversion(char **s, va_list *ap, t_info info)
{
	int				i;
	extern t_table	g_table[];

	i = -1;
	while (++i < 16)
	{
		if (**s == g_table[i].flag)
		{
			g_table[i].function(info, ap);
			break ;
		}
	}
	return (0);
}

int	parseopt(char **s, va_list *ap)
{
	int		format;
	t_info	info;
	int		tmp;

	format = 0;
	info.prec = -1;
	info.zero = 0;
	info.format = &format;
	(*s)++;
	while (isflag(**s) || ft_isdigit(**s) || **s == '.' || isfield(**s))
	{
		if (isflag(**s) || ft_isdigit(**s))
		{
			tmp = parseflags(s, info.format);
			info.zero = (tmp == 0) ? info.zero : tmp;
		}
		if (**s == '.')
			info.prec = parseprecision(s, info.format);
		if (isfield(**s))
			parsefield(s, info.format);
	}
	if (!isconvflag(**s) && **s != '%')
		return (-1);
	parseconversion(s, ap, info);
	return (0);
}
