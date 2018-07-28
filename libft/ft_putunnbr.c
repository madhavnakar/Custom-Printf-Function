/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 12:07:07 by mnakar            #+#    #+#             */
/*   Updated: 2018/07/07 12:40:19 by mnakar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_putdigit(unsigned int n)
{
	char c;

	c = n + '0';
	write(1, &c, 1);
}

void			ft_putunnbr(unsigned int n)
{
	int	next;

	if (n <= 9)
		ft_putdigit(n);
	else
	{
		next = n / 10;
		ft_putnbr(next);
		ft_putdigit(n - next * 10);
	}
}
