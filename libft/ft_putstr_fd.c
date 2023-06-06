/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 21:46:49 by daviles-          #+#    #+#             */
/*   Updated: 2023/04/06 19:19:50 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"
//Sends the string ’s’ to the specified file descriptor

void	ft_putstr_fd(char *s, int fd)
{
	int	c;

	c = 0;
	while (s[c] != '\0')
	{
		write(fd, &s[c], 1);
		c++;
	}
}
/*
int	main(void)
{
	char	s[] = "52 amantes a través del espejo\n";
	int		fd = 1;

	ft_putstr_fd(s, fd);
	return (0);
}
*/
