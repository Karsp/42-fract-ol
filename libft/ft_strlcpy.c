/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 00:07:04 by daviles-          #+#    #+#             */
/*   Updated: 2023/03/24 17:35:34 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"
//copies up to dstsize - 1 characters from the string src to dst,
// NUL-terminating the result if dstsize is not 0. returns the length of src.

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	count;
	size_t	len;

	count = 0;
	len = 0;
	while (((char *) src)[len] != '\0')
		len++;
	if (dstsize != 0)
	{
		while (((char *) src)[count] != '\0' && count < dstsize - 1)
		{
			((char *) dst)[count] = ((char *) src)[count];
			count++;
		}
		((char *) dst)[count] = '\0';
	}
	return (len);
}
/*
int	main(void)
{
	char	src[] = "code breaker";
	char	dst[20];
	int		dstsize;

	dstsize = 4;
	printf("%lu\n", ft_strlcpy(dst, src, dstsize));
	printf("%lu\n", strlcpy(dst, src, dstsize));
	return (0);
}
*/
