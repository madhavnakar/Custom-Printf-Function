/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 12:56:37 by mnakar            #+#    #+#             */
/*   Updated: 2018/07/27 20:44:08 by mnakar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_numlen(long long num, unsigned int base)
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
