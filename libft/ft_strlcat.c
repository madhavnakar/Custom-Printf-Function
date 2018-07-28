/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 19:41:45 by mnakar            #+#    #+#             */
/*   Updated: 2018/06/25 14:44:38 by mnakar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		origdstlen;
	size_t		newdstlen;
	size_t		ind;

	if (dstsize == 0)
		return (ft_strlen(src));
	origdstlen = 0;
	while (dst[origdstlen] && origdstlen < dstsize)
		origdstlen++;
	newdstlen = origdstlen;
	ind = 0;
	while (src[ind] && newdstlen < dstsize - 1)
	{
		dst[newdstlen] = src[ind];
		newdstlen++;
		ind++;
	}
	if (origdstlen < dstsize)
		dst[newdstlen] = '\0';
	return (origdstlen + ft_strlen(src));
}
