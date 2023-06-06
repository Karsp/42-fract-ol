/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 22:26:59 by daviles-          #+#    #+#             */
/*   Updated: 2023/03/24 21:40:45 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"
//The memmove() function copies len bytes from string src to string dst. 
//The two strings may overlap; the copy is always done in a non-destructive
// manner. The memmove() function returns the original value of dst.

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		count;

	count = 0;
	if (src == 0 && dst == 0)
		return (0);
	if (src < dst)
	{
		while ((long)--len >= 0)
			((char *) dst)[len] = ((char *) src)[len];
	}
	else
	{
		while (count < len)
		{
			((char *) dst)[count] = ((char *) src)[count];
			count++;
		}
	}
	return (dst);
}
/*
int	main(void)
{
	char	src[] = "up to you";
	char	dst[0xF0];
	int		len;

	len = 9;
//	dst = src + 1;
	printf("%s\n", ft_memmove(dst, src, len));
//	printf("%s\n", memmove(dst, src, len));
	return (0);
}
*/
