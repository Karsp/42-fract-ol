/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:05:19 by daviles-          #+#    #+#             */
/*   Updated: 2023/03/24 22:45:29 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"
//The strncmp() function compares not more than n characters.return an integer 
//result of the difference from the first different char between s1 and s2.
//The comparison is done using unsigned characters

int	ft_strncmp(const char *s1, const char *s2, size_t size)
{
	size_t	c;

	c = 0;
	while ((s1[c] || s2[c]) && c < size)
	{
		if (s1[c] != s2[c])
			return (((unsigned char *) s1)[c] - ((unsigned char *) s2)[c]);
		c++;
	}
	return (0);
}
/*
int	main(void)
{
	char	s1[] = "asd";
	char	s2[] = "asd";
	int		size = 3;

	printf("%d\n", ft_strncmp(s1, s2, size));
	printf("%d\n", strncmp(s1, s2, size));
	return (0);
}
*/
