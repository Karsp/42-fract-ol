/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:30:08 by daviles-          #+#    #+#             */
/*   Updated: 2023/04/05 22:40:17 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"
//Save (with malloc(3)) and return a new string, formed by the concatenation 
//of ’s1’ and 's2'.

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		c;
	int		i;

	c = 0;
	i = 0;
	s3 = (char *) malloc (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s3)
		return (NULL);
	while (s1[c] != '\0')
	{
		s3[c] = s1[c];
		c++;
	}
	while (s2[i] != '\0')
	{
		s3[c + i] = s2[i];
		i++;
	}
	s3[c + i] = '\0';
	return (s3);
}
/*
int	main(void)
{
	char	s1[] = "Mientras llovia ";
	char	s2[] = "en Macondo";

	printf("%s\n", ft_strjoin(s1, s2));
	return (0);
}
*/
