/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 17:53:16 by mnakar            #+#    #+#             */
/*   Updated: 2018/06/25 15:15:05 by mnakar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	size;
	char	*new;
	int		ind;

	if (!s || !f)
		return (NULL);
	ind = 0;
	size = ft_strlen(s);
	new = ft_strnew(size);
	if (!new)
		return (NULL);
	while (ind < (int)size)
	{
		new[ind] = f(s[ind]);
		ind++;
	}
	return (new);
}
