/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 09:28:39 by mnakar            #+#    #+#             */
/*   Updated: 2018/06/25 16:21:50 by mnakar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*tail;
	char	*newstr;
	int		ind;
	int		str_len;

	tail = (char *)s;
	str_len = ft_strlen(s);
	tail += str_len;
	if (str_len == 0)
		return ((char *)s);
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	while (*tail == ' ' || *tail == '\n' || *tail == '\t' || *tail == 0)
		tail--;
	if ((int)(tail - s) == str_len || tail < s)
		return ((char *)s);
	newstr = (char *)malloc(sizeof(char) * ((int)(tail - s + 2)));
	if (!newstr)
		return (NULL);
	ind = 0;
	while (s <= tail)
		newstr[ind++] = (char)*s++;
	newstr[ind] = '\0';
	return (newstr);
}
