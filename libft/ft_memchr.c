/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 20:43:40 by daviles-          #+#    #+#             */
/*   Updated: 2023/04/05 15:07:19 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"
//The memchr() function locates the first occurrence of c (converted to an 
//unsigned char) in string s.The memchr() function returns a pointer to the 
//byte located, or NULL if no such byte exists within n bytes.

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				count;

	count = 0;
	while (count < n)
	{
		if (((unsigned char *) s)[count] == ((unsigned char) c))
			return (&((char *) s)[count]);
		count++;
	}
	return (0);
}
/*
#include<stdio.h>
#include<string.h>

int	main(void)
{
	char	s[] = "Como mola";
	int		c;
	int		n;

	c =111; 
	n = 3;
	printf("%s\n", ft_memchr(s, c, n));
	printf("%s\n", memchr(s, c, n));
	return (0);
}
*/
