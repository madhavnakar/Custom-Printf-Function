/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 19:35:07 by mnakar            #+#    #+#             */
/*   Updated: 2018/06/24 20:01:30 by mnakar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*dest;
	char	*source;
	size_t	ind;

	dest = (char *)dst;
	source = (char *)src;
	ind = 0;
	while (ind < n)
	{
		dest[ind] = source[ind];
		if (source[ind] == (char)c)
			return (&dest[ind + 1]);
		ind++;
	}
	return (NULL);
}
