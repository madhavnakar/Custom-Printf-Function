/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 20:20:11 by mnakar            #+#    #+#             */
/*   Updated: 2018/06/23 15:54:11 by mnakar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char			*str;
	unsigned char	ch;
	size_t			ind;

	str = (char *)b;
	ch = (unsigned char)c;
	ind = 0;
	while (ind < len)
	{
		str[ind] = ch;
		ind++;
	}
	return (b);
}
