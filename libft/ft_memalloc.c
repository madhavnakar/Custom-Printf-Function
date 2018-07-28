/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 20:27:53 by mnakar            #+#    #+#             */
/*   Updated: 2018/06/24 21:44:13 by mnakar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*ptr;
	size_t	counter;

	ptr = (char *)malloc(size);
	if (!ptr)
		return (NULL);
	counter = 0;
	while (counter < size)
	{
		ptr[counter] = 0;
		counter++;
	}
	return ((void *)ptr);
}
