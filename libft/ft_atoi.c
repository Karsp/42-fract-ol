/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:11:28 by daviles-          #+#    #+#             */
/*   Updated: 2023/04/01 18:41:33 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"
//converts the initial portion of the string pointed to by str to int 
//representation.

int	ft_atoi(const char *str)
{
	int	c;
	int	r;
	int	s;

	c = 0;
	r = 0;
	s = 1;
	while ((str[c] > 8 && str[c] < 14) || str[c] == 32)
		c++;
	if (str[c] == '+' || str[c] == '-')
	{
		if (str[c] == '-')
			s = -1;
		c++;
	}
	while (str[c] != '\0' && (str[c] >= '0' && str[c] <= '9'))
	{
		r = r * 10 + (str[c] - 48);
		c++;
	}
	return (r * s);
}
/*
int	main(void)
{
	char	str[] = "054854";

	printf("%d\n", ft_atoi(str));
	printf("%d\n", atoi(str));
	return (0);
}
*/
