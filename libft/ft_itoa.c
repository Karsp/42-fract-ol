/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:46:50 by daviles-          #+#    #+#             */
/*   Updated: 2023/04/05 22:42:53 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"
//Using malloc(3), generate a string that represents the integer value 
//received as an argument. Negative numbers have to be managed.

static int	ft_sizeint(int n)
{
	if (n == 0)
		return (0);
	return (1 + ft_sizeint(n / 10));
}

static char	*ft_inttostr(int n, int size, char *str)
{
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[--size] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}

static void	ft_isnegative(int *n, int *size, int *sign)
{
	int	*pn;
	int	*psize;
	int	*psign;

	pn = n;
	psize = size;
	psign = sign;
	if (*pn == -2147483648)
	{
	*pn = 147483648;
	*psize = 11;
	*psign = 2;
	}
	else if (*pn == 0)
		*psize = 1;
	else if (*pn < 0)
	{
		*pn *= -1;
		*psize = ft_sizeint(*pn) + 1;
		*psign = 1;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		size;
	int		sign;

	size = 0;
	sign = 0;
	if (n <= 0)
		ft_isnegative(&n, &size, &sign);
	else
		size = ft_sizeint(n);
	str = (char *) ft_calloc (size + 1, 1);
	if (!str)
		return (NULL);
	if (sign)
		str[0] = '-';
	if (sign == 2)
		str[1] = '2';
	str = ft_inttostr(n, size, str);
	return (str);
}
/*
int	main(void)
{
	int	n;

	n = -123210;
	printf("%s\n", ft_itoa(n));
	return (0);
}
*/
