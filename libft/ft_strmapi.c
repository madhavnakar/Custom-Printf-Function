/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 17:59:57 by mnakar            #+#    #+#             */
/*   Updated: 2018/06/25 15:15:49 by mnakar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	size;
	char	*new;
	int		ind;

	if (!s || !f)
		return (NULL);
	ind = 0;
	size = (size_t)ft_strlen(s);
	new = ft_strnew(size);
	if (!new)
		return (NULL);
	while (ind < (int)size)
	{
		new[ind] = f(ind, s[ind]);
		ind++;
	}
	return (new);
}
