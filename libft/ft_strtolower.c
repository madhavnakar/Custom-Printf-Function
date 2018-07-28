/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 19:19:57 by mnakar            #+#    #+#             */
/*   Updated: 2018/07/22 17:31:57 by mnakar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtolower(char *s)
{
	char *str;

	str = s;
	if (!s)
		return (NULL);
	while (*s)
	{
		*s = ft_tolower(*s);
		s++;
	}
	return (str);
}
