/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 21:36:35 by daviles-          #+#    #+#             */
/*   Updated: 2023/04/05 15:11:23 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"
//copies n bytes from memory area src to memory area dst.  If dst and src 
//overlap, behavior is undefined.  Applications in which dst and src might 
//overlap should use memmove(3) instead.

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		count;

	count = 0;
	if (((char *) src) == '\0' && ((char *) dst) == '\0')
		return (0);
	while (count < n)
	{
		((char *) dst)[count] = ((char *) src)[count];
		count++;
	}
	return (dst);
}
/*
int	main(void)
{
	char	str[] = "me gusta madrid";
	char	dst[0];
	int		n;

	n = 8;
	printf("%s\n", ft_memcpy(((void *)0), ((void *)0), 3));
//	printf("%s\n", memcpy((void *)0), ((void *)0), 3);
	return (0);
}
*/
