/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_arr_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 19:16:35 by mnakar            #+#    #+#             */
/*   Updated: 2018/06/24 19:18:06 by mnakar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_num_arr_push(int *nums, int numsize, int val)
{
	int nextreplace;
	int ind;

	ind = 0;
	nextreplace = 0;
	while (ind < numsize)
	{
		if (nums[ind] != val)
			nums[nextreplace++] = nums[ind];
		ind++;
	}
	return (nextreplace);
}
