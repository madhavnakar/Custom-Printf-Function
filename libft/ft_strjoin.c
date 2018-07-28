/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 09:06:49 by mnakar            #+#    #+#             */
/*   Updated: 2018/06/25 15:17:46 by mnakar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_len;
	int		s2_len;
	char	*strjoin;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	strjoin = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!strjoin)
		return (NULL);
	strjoin[s1_len + s2_len] = '\0';
	while (s2_len)
	{
		s2_len--;
		strjoin[s2_len + s1_len] = s2[s2_len];
	}
	while (s1_len)
	{
		s1_len--;
		strjoin[s1_len] = s1[s1_len];
	}
	return (strjoin);
}
