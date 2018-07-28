/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_funcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 12:58:37 by mnakar            #+#    #+#             */
/*   Updated: 2018/07/28 14:24:59 by mnakar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long		clear_bits(long long n, int bits)
{
	return ((bits == LLONG) ? n : ((0x1ul << (bits)) - 1) & n);
}

long long	negate(long long n, int bits)
{
	return ((((0x1ul << bits) - 1) ^ n) + 1);
}

size_t		numlen_x(unsigned long long num, unsigned int base)
{
	size_t counter;

	counter = 0;
	if (!num)
		return (1);
	while (num)
	{
		counter++;
		num /= base;
	}
	return (counter);
}
