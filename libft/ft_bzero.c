/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzero.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:19:07 by daviles-          #+#    #+#             */
/*   Updated: 2023/03/24 15:07:15 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"
// The bzero() function writes n zeroed bytes to the
// string s.  If n is zero, bzero() does nothing.

void	ft_bzero(void *s, size_t n)
{
	size_t	count;

	count = 0;
	while (count < n)
	{
		((char *) s)[count] = '\0';
		count++;
	}
}
/*
#include<stdio.h>
#include<string.h>

int	main(void)
{
	char	str[] = "lalolanda";
	int		size;

	size = 4;
	ft_bzero(str, size);
//	bzero(str, size);
	printf("%s\n", str);	
	return (0);
}
*/
