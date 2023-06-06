/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalnum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:15:29 by daviles-          #+#    #+#             */
/*   Updated: 2023/04/05 14:42:51 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"
//The isalnum() function tests for any character for which isalpha(3) or 
//isdigit(3) is  true. The isalnum() function returns zero if the character 
//tests false and returns non-zero if the character tests true.

int	ft_isalnum(int c)
{
	if (ft_isdigit(c) == 1 || ft_isalpha(c) == 1)
		return (1);
	else
		return (0);
}
/*
int	main(void)
{
	char	a;
	char	b;

	a = 2;
	b = 97;
	printf("%d\n", ft_isalnum(a));
	printf("%d\n", ft_isalnum(b));
	return (0);
}
*/
