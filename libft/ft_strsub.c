/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 21:14:38 by mnakar            #+#    #+#             */
/*   Updated: 2018/06/25 15:17:08 by mnakar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	int		strlength;
	int		end;
	char	*strsub;
	char	*strsub_head;

	if (!s)
		return (NULL);
	strlength = ft_strlen(s);
	if ((int)start + (int)len > strlength)
		return (NULL);
	end = (int)start + (int)len;
	strsub = (char *)malloc(sizeof(char) * (len + 1));
	if (!strsub)
		return (NULL);
	strsub_head = strsub;
	while (start < (unsigned int)end)
	{
		*strsub = s[start];
		start++;
		strsub++;
	}
	*strsub = '\0';
	return (strsub_head);
}
