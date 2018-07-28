/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 18:38:33 by mnakar            #+#    #+#             */
/*   Updated: 2018/06/23 17:04:33 by mnakar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*hayptr;
	char	*needleptr;
	size_t	len_temp;

	if (needle[0] == '\0')
		return (char *)haystack;
	while (*haystack && len)
	{
		len_temp = len;
		if (*haystack == *needle)
		{
			hayptr = (char *)haystack;
			needleptr = (char *)needle;
			while (*hayptr && *needleptr && *hayptr == *needleptr && len_temp--)
			{
				hayptr++;
				needleptr++;
			}
			if (*needleptr == '\0')
				return (char *)haystack;
		}
		haystack++;
		len--;
	}
	return (NULL);
}
