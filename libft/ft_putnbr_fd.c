/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 21:58:16 by daviles-          #+#    #+#             */
/*   Updated: 2023/04/06 19:18:17 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"
//Sends the number ’n’ to the given file descriptor.

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_fd((n * -1), fd);
	}
	else if ((n / 10) == 0)
	{
		c = n + 48;
		write(fd, &c, 1);
	}
	else
	{
		ft_putnbr_fd((n / 10), fd);
		c = (n % 10) + 48;
		write(fd, &c, 1);
	}
}
/*
int	main(void)
{
	int	n;
	int	fd;

	fd = 1;
	n = -21474;
	ft_putnbr_fd(n, fd);
	return (0);
}
*/
