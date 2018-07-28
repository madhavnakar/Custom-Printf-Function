/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 15:04:43 by mnakar            #+#    #+#             */
/*   Updated: 2018/07/27 20:14:06 by mnakar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	isneg(long long n, int bits, int isfinalcall)
{
	extern int	g_count;
	int			isexception;

	isexception = 0;
	if (bits == SCHAR && n == (0x1 << (SCHAR - 1)))
		isexception += 1;
	else if (bits == SHORT && n == (0x1 << (SHORT - 1)))
		isexception += 1;
	else if (bits == INT && n == (0x1l << (INT - 1)))
		isexception += 1;
	else if (bits == LONG && n == (0x1l << (LONG - 1)))
		isexception += 1;
	else if (bits == LLONG && n == (0x1ll << (LLONG - 1)))
		isexception += 1;
	if (isexception)
	{
		if (isfinalcall)
			g_count++;
		return (0);
	}
	return (((0x1ll << (bits - 1)) & n) >> (bits - 1));
}

int	isflag(char c)
{
	return (c == '-' || c == '+' || c == ' ' || c == '0' || c == '#');
}

int	isfield(char c)
{
	return (c == 'h' || c == 'l' || c == 'j' || c == 'z');
}

int	isconvflag(char c)
{
	return (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' ||
			c == 'i' || c == 'o' || c == 'O' || c == 'u' || c == 'U' ||
			c == 'x' || c == 'X' || c == 'c' || c == 'C' || c == 'b');
}
