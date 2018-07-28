/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 18:16:19 by mnakar            #+#    #+#             */
/*   Updated: 2018/06/24 20:39:22 by mnakar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		absval_fd(int n, int fd)
{
	if (n < 0)
		write(fd, "-", 1);
	return ((n < 0) ? (-1) * n : n);
}

static void		ft_putdigit_fd(int n, int fd)
{
	char c;

	n = absval_fd(n, fd);
	c = n + '0';
	write(fd, &c, 1);
}

void			ft_putnbr_fd(int n, int fd)
{
	int	next;

	if (-9 <= n && n <= 9)
		ft_putdigit_fd(n, fd);
	else if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	else
	{
		n = absval_fd(n, fd);
		next = n / 10;
		ft_putnbr_fd(next, fd);
		ft_putdigit_fd(n - next * 10, fd);
	}
}
