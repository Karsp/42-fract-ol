/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 21:52:02 by daviles-          #+#    #+#             */
/*   Updated: 2023/04/06 19:18:50 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"
//Send the string ’s’ to the given file descriptor, followed by a line break.

void	ft_putendl_fd(char *s, int fd)
{
	int	c;

	c = 0;
	while (s[c] != '\0')
	{
		write(fd, &s[c], 1);
		c++;
	}
	write(fd, "\n", 1);
}
/*
int	main(void)
{
	char	s[] = "Hiroshima mon amour.";
	int		fd;

	fd = 1;
	ft_putendl_fd(s, fd);
	return (0);
}
*/
