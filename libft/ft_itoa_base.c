/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 08:29:56 by mnakar            #+#    #+#             */
/*   Updated: 2018/07/27 20:46:08 by mnakar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_numlenx(unsigned long long num, unsigned int base)
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

char	*ft_itoa_base(unsigned long long value, int base)
{
	int					is_neg;
	char				*nbr;
	int					len;
	unsigned long long	n;

	n = (unsigned long long)value;
	len = 0;
	is_neg = 0;
	len = ft_numlenx(n, base);
	if (!(nbr = (char *)malloc(sizeof(char) * (len + is_neg + 1))))
		return (NULL);
	if (is_neg)
		nbr[0] = '-';
	nbr[len + is_neg] = 0;
	while (len-- > 0)
	{
		nbr[len + is_neg] = (n % base) + (n % base > 9 ? 'A' - 10 : '0');
		n /= base;
	}
	return (nbr);
}
