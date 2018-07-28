/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 14:39:26 by mnakar            #+#    #+#             */
/*   Updated: 2018/06/22 18:48:48 by mnakar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	int ind;

	ind = 0;
	while (*src && len)
	{
		dst[ind] = *src;
		src++;
		ind++;
		len--;
	}
	while (len)
	{
		dst[ind] = '\0';
		ind++;
		len--;
	}
	return (dst);
}
