/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:52:41 by daviles-          #+#    #+#             */
/*   Updated: 2023/03/27 17:31:22 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"
//contiguously allocates enough space for count objects that are size bytes of
// memory each and returns a pointer to the allocated memory.  The allocated 
// memory is filled with bytes of value zero.

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	c;

	c = 0;
	ptr = (void *) malloc (count * size);
	if (!ptr)
		return (NULL);
	while (c < (count * size))
	{
		((char *) ptr)[c] = '\0';
		c++;
	}
	return (ptr);
}
/*
int	main(void)
{
	size_t	count;
	size_t	size;
	char	*ptr;

	size = 4;
	count = 7;
	ptr = ft_calloc(count, size);
	printf("%s\n", ptr);
	return(0);
}
*/
