/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 10:56:43 by mnakar            #+#    #+#             */
/*   Updated: 2018/07/08 21:03:23 by mnakar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthex(unsigned long num, int capital, int bytes, int ptr)
{
	unsigned long	trav;
	unsigned long	hex;
	int				i;
	int				beg_z;

	i = bytes * 2 - 1;
	trav = (0xFl) << (i * 4);
	beg_z = 0;
	(ptr) ? ft_putstr("0x") : 0;
	while (trav)
	{
		while (!beg_z && !(hex = (num & trav) >> (i * 4)) && (i--))
			trav >>= 4;
		if ((hex <= 9 && hex) || (!hex && !beg_z))
			ft_putnbr(hex);
		beg_z = 1;
		if (capital && hex > 9)
			ft_putchar(hex + 'A' - 10);
		else if (hex > 9)
			ft_putchar(hex + 'a' - 10);
		trav >>= 4;
		i--;
		hex = num & trav;
		hex >>= (i * 4);
	}
}
