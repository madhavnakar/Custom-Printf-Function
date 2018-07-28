/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 15:01:53 by mnakar            #+#    #+#             */
/*   Updated: 2018/06/22 18:51:32 by mnakar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char *hayptr;
	char *needleptr;

	if (needle[0] == '\0')
		return (char *)haystack;
	while (*haystack)
	{
		if (*haystack == *needle)
		{
			hayptr = (char *)haystack;
			needleptr = (char *)needle;
			while (*hayptr && *needleptr && *hayptr == *needleptr)
			{
				hayptr++;
				needleptr++;
			}
			if (*needleptr == '\0')
				return (char *)haystack;
		}
		haystack++;
	}
	return (NULL);
}
