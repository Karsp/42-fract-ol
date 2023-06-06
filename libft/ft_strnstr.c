/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:17:05 by daviles-          #+#    #+#             */
/*   Updated: 2023/03/27 15:11:13 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"
//locates the first occurrence of the null-terminated string needle in the 
//string  haystack, where not more than len characters are searched.
// If needle is an empty string, haystack is returned; if needle occurs nowhere
//  in haystack, NULL is returned; otherwise a pointer to the first character 
//  of the first occurrence of needle is returned.

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	c;
	size_t	s;
	size_t	f;

	c = 0;
	s = ft_strlen(needle);
	if (needle == '\0' || s < 1)
		return ((char *)haystack);
	while (haystack[c] != '\0' && c < len)
	{
		s = 0;
		if (haystack[c] == needle [s])
		{
			f = c;
			while (needle[s] == haystack[c + s] && (c + s) < len
				&& haystack[c + s] != '\0')
				s++;
			if (needle[s] == '\0')
				return (&((char *)haystack)[f]);
		}
		c++;
	}
	return (NULL);
}
/*
#include<string.h>

int	main(void)
{
	char	haystack[] = "I want to be forever young";
	char	needle [] = "e";
	size_t	len;

	len = 12;
	printf("%s\n", ft_strnstr(haystack, needle, len));
	printf("%s\n", strnstr(haystack, needle, len));
	return (0);
}
*/
