/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:35:47 by daviles-          #+#    #+#             */
/*   Updated: 2023/03/24 14:48:47 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"
//The strchr() function locates the first occurrence of c (converted to a 
//char) in the string pointed to by s.  The terminating null character is
// considered to be part of the string; therefore if c is `\0', the functions
// locate the terminating `\0'.

char	*ft_strchr(const char *s, int c)
{
	int		count;

	count = 0;
	while (((char *) s)[count] != '\0')
	{
		if (((char *) s)[count] == ((char) c))
			return (&((char *) s)[count]);
		count++;
	}
	if ((char) c == '\0')
		return (&((char *) s)[count]);
	return (0);
}
/*
int	main(void)
{
	char	s[] = "hola";
	int		c;

	c = 0;
	printf("%s\n", ft_strchr(s, c));
//	printf("%s\n", strchr(s, c));
	return (0);
}
*/
