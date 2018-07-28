/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 14:26:50 by mnakar            #+#    #+#             */
/*   Updated: 2018/06/22 18:50:47 by mnakar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	ch;
	char	*str;

	str = (char *)s;
	ch = (char)c;
	if (*str == '\0' && c == '\0')
		return (str);
	while (*str)
	{
		if (*str == ch)
			return (str);
		str++;
	}
	return ((!c) ? str : NULL);
}
