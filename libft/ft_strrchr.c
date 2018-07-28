/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 14:28:46 by mnakar            #+#    #+#             */
/*   Updated: 2018/06/22 18:51:10 by mnakar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	ch;
	char			*head;
	char			*tail;

	ch = (unsigned char)c;
	head = (char *)s;
	tail = head;
	while (*tail)
		tail++;
	if (*tail == ch)
		return (tail);
	while (tail != head)
	{
		tail--;
		if (*tail == ch)
			return (tail);
	}
	return (NULL);
}
