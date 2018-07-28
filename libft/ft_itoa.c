/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 21:04:59 by mnakar            #+#    #+#             */
/*   Updated: 2018/06/25 10:21:54 by mnakar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_num_len(int n)
{
	int count;

	count = 0;
	if (n < 0)
		count++;
	n *= -1;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void		filler(char **num_trav, int n, int is_neg)
{
	while (n != 0)
	{
		**num_trav = (n - (n / 10) * 10) + '0';
		n = n / 10;
		*num_trav = *num_trav - 1;
	}
	if (is_neg)
		**num_trav = '-';
}

char			*ft_itoa(int n)
{
	char	*num_str;
	char	*num_trav;
	int		is_neg;

	if (n == 0 || n == -2147483648)
		return ((n == 0) ? ft_strdup("0") : ft_strdup("-2147483648"));
	num_str = (char *)malloc(sizeof(char) * (get_num_len(n) + 1));
	if (!num_str)
		return (NULL);
	num_trav = num_str + get_num_len(n);
	*num_trav = '\0';
	is_neg = 0;
	if (n < 0)
	{
		is_neg = 1;
		n *= -1;
	}
	num_trav--;
	filler(&num_trav, n, is_neg);
	return ((is_neg) ? num_trav : num_trav + 1);
}
