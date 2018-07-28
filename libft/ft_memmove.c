/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 13:04:00 by mnakar            #+#    #+#             */
/*   Updated: 2018/06/23 11:01:42 by mnakar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*pdst;
	char	*psrc;
	size_t	ind;

	pdst = (char *)dst;
	psrc = (char *)src;
	ind = 0;
	if (pdst > psrc)
		while (len--)
			pdst[len] = psrc[len];
	else
		while (ind < len)
		{
			pdst[ind] = psrc[ind];
			ind++;
		}
	return (pdst);
}
