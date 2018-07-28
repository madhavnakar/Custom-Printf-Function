/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 14:49:20 by mnakar            #+#    #+#             */
/*   Updated: 2018/06/25 13:51:55 by mnakar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned long	total;
	int				neg;

	total = 0;
	neg = 0;
	while (*str == '\t' || *str == '\n' || *str == '\r' ||
			*str == '\f' || *str == '\v' || *str == ' ')
		str++;
	if ((!('0' <= *str && *str <= '9')) && *str != '-' && *str != '+')
		return (0);
	if (*str == '-')
	{
		neg = 1;
		str++;
	}
	else if (*str == '+')
		str++;
	while ('0' <= *str && *str <= '9')
	{
		total = total * 10 + (*str - '0');
		str++;
	}
	if (total > 9223372036854775807)
		return ((neg) ? 0 : -1);
	return ((neg) ? (int)((-1) * total) : (int)(total));
}
