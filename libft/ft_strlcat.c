/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:36:42 by daviles-          #+#    #+#             */
/*   Updated: 2023/04/05 15:41:39 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"
//Appends string src to the end of dst. It will append at most 
//dstsize - strlen(dst) - 1 characters.  It will then NUL-terminate, unless 
//dstsize is 0 or the original dst string was longer than dstsize (in 
//practice this should not     happen as it means that either dstsize is 
//incorrect or that dst is not a proper string). If the src and dst strings
//overlap, the behavior  is undefined.
//dstsize tiene en cuenta los caracteres que hay en dst y el null del final.

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	c;
	size_t	i;
	size_t	slen;
	size_t	dlen;

	i = 0;
	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	c = dlen;
	if (dst == 0)
		return (slen);
	if (dstsize <= c)
		return (dstsize + slen);
	while (src[i] != '\0' && i < dstsize - dlen - 1)
	{
		dst[c] = src[i];
		i++;
		c++;
	}
	dst[c] = '\0';
	return (dlen + slen);
}
/*
int	main(void)
{
	char	src[] = "que pasa si termino la libft y no uso nunca nunca...";
	char	dst[14] = "ab";
	int		dstsize;
	
	//dstsize = 4;
	//printf("%s\n",dst);
	printf("%lu\n", strlcat("pqrstuvwxyz", "abcd", 20));
	//printf("%lu\n", strlcat(dst, src, dstsize));
	//printf("%s\n", dst);
	return (0);
}
*/
