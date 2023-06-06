/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:47:59 by daviles-          #+#    #+#             */
/*   Updated: 2023/04/05 22:41:03 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"
//Remove all characters from the string ’set’ from the beginning and from the 
//end of ’s1’, until find a character not belonging to ’set’. The resulting 
//string is returned with a fallback of malloc(3)

static int	ft_settrue(char const *s1, char const *set, size_t c)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (s1[c] == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	size_t	c;
	size_t	s;
	size_t	e;

	c = 0;
	s = 0;
	e = ft_strlen(s1);
	while (ft_settrue(s1, set, s) && s1[s] != '\0')
	{
		s++;
		if (s1[s] == '\0')
		{
			s2 = (char *) ft_calloc (1, 1);
			return (s2);
		}
	}
	while (e > s && ft_settrue(s1, set, e - 1))
		e--;
	s2 = (char *) ft_calloc (e - s + 1, 1);
	if (!s2)
		return (NULL);
	while (s < e)
		s2[c++] = s1[s++];
	return (s2);
}
/*
int	main(void)
{
	char	s1[] = "lorem \n ipsum \t dolor \n sit \t amet";
	char	set[] = " ";

	printf("%s\n", ft_strtrim(s1, set));
	return (0);
}
*/
