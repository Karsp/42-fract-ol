/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:14:23 by daviles-          #+#    #+#             */
/*   Updated: 2023/03/24 20:38:37 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"
//The memcmp() function compares byte string s1 against byte string s2.
// Both strings are assumed to be n bytes long.The memcmp() function returns 
// zero if the two strings are identical, otherwise returns the difference 
// between the first two. Zero-length strings are always identical.

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		c;

	c = 0;
	while (c < n)
	{
		if (((unsigned char *) s1)[c] != ((unsigned char *) s2)[c])
			return (((unsigned char *) s1)[c] - ((unsigned char *) s2)[c]);
		c++;
	}
	return (0);
}
/*

int	main(void)
{
	char	s1 [] = "t\200";
	char	s2 [] = "t\0";
	size_t	n;

	n = 2;
	printf("%d\n", ft_memcmp(s1, s2, n));
	printf("%d\n", memcmp(s1, s2, n));
	return (0);
}
*/
