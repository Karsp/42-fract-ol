/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:31:29 by daviles-          #+#    #+#             */
/*   Updated: 2023/03/31 15:34:43 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"
//The strdup() function save a copy of a string. allocates sufficient memory 
//for a copy of the string s1, does the copy, and returns a pointer to it.
//If insufficient memory is available, NULL is returned

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		c;

	c = 0;
	ptr = (char *) malloc (ft_strlen(s1) + 1);
	if (!ptr)
		return (NULL);
	while (s1[c] != '\0')
	{
		ptr[c] = s1[c];
		c++;
	}
	ptr[c] = '\0';
	return (ptr);
}
/*
int	main(void)
{
	char	s1[] = "Mambo que rico el mambo";

	printf("%s\n", ft_strdup(s1));
	printf("%s\n", strdup(s1));
	return (0);
}
*/
