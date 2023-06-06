/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:44:19 by daviles-          #+#    #+#             */
/*   Updated: 2023/03/23 20:07:29 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"
//The strlen() function returns the number of characters that precede the 
//terminating NUL charac ter.

size_t	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	while (((char *) s)[count] != '\0')
		count++;
	return (count);
}
