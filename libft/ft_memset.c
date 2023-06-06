/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:59:00 by daviles-          #+#    #+#             */
/*   Updated: 2023/03/24 15:45:24 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"
//The memset() function writes len bytes of value c (converted to an unsigned
// char) to the string b. The memset() function returns its first argument.

void	*ft_memset(void *b, int c, size_t size)
{
	size_t		count;

	count = 0;
	if (size < 1)
		return (b);
	while (count < size)
	{
		((char *) b)[count] = (unsigned char) c;
		count++;
	}
	return (b);
}
/*
int	main(void)
{
	char	str[] = "hola mundo";

//	printf("%s\n", ft_memset(str, 'A', 0));
	printf("%s\n", memset(str, 'A', 0));
	return (0);
}
*/
