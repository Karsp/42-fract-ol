/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:07:12 by daviles-          #+#    #+#             */
/*   Updated: 2023/04/05 22:37:41 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"
//Save (with malloc(3)) and return a substring of the string 's'. The substring 
//starts from index ’start’ and has a maximum length 'len'.

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	c;

	c = 0;
	if (len > ft_strlen(s))
		sub = (char *) malloc (ft_strlen(s) + 1);
	else
		sub = (char *) malloc (len + 1);
	if (!sub)
		return (NULL);
	if (start < ft_strlen(s))
	{
		while (s[start + c] != '\0' && c < len)
		{
			sub[c] = s[start + c];
			c++;
		}
	}
	sub[c] = '\0';
	return (sub);
}
/*
int	main(void)
{
	char	s[] = "El amor despues del amor";
	size_t	start;
	size_t	len;

	start = 5;
	len = 5;
	printf("%s\n", ft_substr(s, 400, 20));
	return (0);
}
*/
