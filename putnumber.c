/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnumber.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 12:47:08 by mnakar            #+#    #+#             */
/*   Updated: 2018/07/27 19:56:14 by mnakar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_putschar(signed char n)
{
	if (0 <= n && n <= 9)
		ft_putchar(n + '0');
	else if (n > 9)
	{
		ft_putschar(n / 10);
		ft_putchar((n % 10) + '0');
	}
	else
	{
		ft_putchar('-');
		if (n <= -10)
			ft_putschar(-1 * (n / 10));
		ft_putchar(-1 * (n % 10) + '0');
	}
}

void			ft_putshort(short n)
{
	if (0 <= n && n <= 9)
		ft_putchar(n + '0');
	else if (n > 9)
	{
		ft_putshort(n / 10);
		ft_putchar((n % 10) + '0');
	}
	else
	{
		ft_putchar('-');
		if (n <= -10)
			ft_putshort(-1 * (n / 10));
		ft_putchar(-1 * (n % 10) + '0');
	}
}

void			ft_putlong(long n)
{
	if (0 <= n && n <= 9)
		ft_putchar(n + '0');
	else if (n > 9)
	{
		ft_putlong(n / 10);
		ft_putchar((n % 10) + '0');
	}
	else
	{
		ft_putchar('-');
		if (n <= -10)
			ft_putlong(-1 * (n / 10));
		ft_putchar(-1 * (n % 10) + '0');
	}
}

void			ft_putlonglong(long long n)
{
	if (0 <= n && n <= 9)
		ft_putchar(n + '0');
	else if (n > 9)
	{
		ft_putlonglong(n / 10);
		ft_putchar((n % 10) + '0');
	}
	else
	{
		ft_putchar('-');
		if (n <= -10)
			ft_putlonglong(-1 * (n / 10));
		ft_putchar(-1 * (n % 10) + '0');
	}
}
