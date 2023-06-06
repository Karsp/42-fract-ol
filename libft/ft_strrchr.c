/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:55:12 by daviles-          #+#    #+#             */
/*   Updated: 2023/03/24 17:57:48 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"
//The strchr() function locates the first occurrence of c (converted to a char)
// in the string pointed to by s.  The terminating null character is considered
//  to be part of the string; therefore if c is `\0', the functions locate the
//   terminating `\0'. The functions strchr() and strrchr() return a pointer
//    to the located character, or NULL if the character does not appear in
//     the string. The strrchr() function is identical to strchr(), except it
//     locates the last occurrence of c.

char	*ft_strrchr(const char *s, int c)
{
	int		count;
	int		found;

	count = 0;
	found = -1;
	while (((char *) s)[count] != '\0')
	{
		if (((char *) s)[count] == ((char) c))
			found = count;
		count++;
	}
	if (((char) c) == '\0')
		return (&((char *) s)[count]);
	if (found != -1)
		return (&((char *) s)[found]);
	return (0);
}
/*
int	main(void)
{
	char	str[] = "abbbbbbbb";
	int		c;

	c = 97;
	printf("%s\n", ft_strrchr(str, 'a'));
	printf("%s\n", strrchr(str, 'a'));
	return (0);
}
*/
