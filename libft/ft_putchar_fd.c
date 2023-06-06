/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 21:14:11 by daviles-          #+#    #+#             */
/*   Updated: 2023/04/06 19:20:43 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"
//Sends the character ’c’ to the specified file descriptor.

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
int	main(void)
{
	char	c;
	int fd;

	fd = 1;
	c = 'A';
	ft_putchar_fd(c, fd);
	return (0);
}	
*/
