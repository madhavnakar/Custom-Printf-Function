/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 08:55:21 by mnakar            #+#    #+#             */
/*   Updated: 2018/06/24 13:18:19 by mnakar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*prev;
	t_list	*next;

	if (*alst == NULL)
		return ;
	next = (*alst)->next;
	ft_lstdelone(alst, del);
	while (next != NULL)
	{
		prev = next;
		next = next->next;
		ft_lstdelone(&prev, del);
	}
}
