/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 16:46:34 by knovytsk          #+#    #+#             */
/*   Updated: 2017/11/09 12:15:12 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char			c;
	unsigned int	num;

	num = n;
	if (n < 0)
	{
		num = n * (-1);
		write(fd, "-", 1);
	}
	if (num > 9)
		ft_putnbr_fd((num / 10), fd);
	c = (num % 10) + 48;
	write(fd, &c, 1);
}
