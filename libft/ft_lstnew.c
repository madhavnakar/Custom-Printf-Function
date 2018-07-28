/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 18:53:15 by mnakar            #+#    #+#             */
/*   Updated: 2018/06/24 10:22:25 by mnakar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*nodeptr;
	char	*ptr;
	char	*cont;

	nodeptr = (t_list *)malloc(sizeof(t_list));
	if (!nodeptr)
		return (NULL);
	if (content == NULL)
	{
		nodeptr->content = NULL;
		nodeptr->content_size = 0;
	}
	else
	{
		nodeptr->content_size = content_size;
		nodeptr->content = (void *)malloc(content_size);
		ptr = nodeptr->content;
		cont = (char *)content;
		while ((int)(--content_size) != -1)
			ptr[content_size] = cont[content_size];
	}
	nodeptr->next = (struct s_list *)malloc(sizeof(struct s_list));
	nodeptr->next = NULL;
	return (nodeptr);
}
