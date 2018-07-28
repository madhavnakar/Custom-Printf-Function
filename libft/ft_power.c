/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 15:59:20 by mnakar            #+#    #+#             */
/*   Updated: 2018/06/24 16:24:28 by mnakar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_power(int base, int exp)
{
	int part;

	if (base == 0 || exp == 0)
		return ((exp == 0) ? 1 : 0);
	if (exp == 1)
		return (base);
	else
	{
		part = ft_power(base, exp / 2);
		if (exp % 2 == 0)
			return (part * part);
		else
			return (base * part * part);
	}
}
