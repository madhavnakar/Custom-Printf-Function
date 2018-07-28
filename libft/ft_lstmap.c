/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 12:32:28 by mnakar            #+#    #+#             */
/*   Updated: 2018/06/24 13:16:28 by mnakar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*list;

	if (lst == NULL)
		return (NULL);
	list = f(lst);
	head = list;
	while (lst->next)
	{
		list->next = f(lst->next);
		if (list->next == NULL)
		{
			free(list->next);
			return (NULL);
		}
		list = list->next;
		lst = lst->next;
	}
	return (head);
}
