/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:35:19 by daviles-          #+#    #+#             */
/*   Updated: 2023/06/05 12:38:37 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"

int	ft_putnbr(int n, int *res)
{
	char	c;

	if (n == -2147483648)
		*res += write(1, "-2147483648", 11);
	else if (n < 0)
	{
		write(1, "-", 1);
		*res += 1;
		ft_putnbr((n * -1), res);
	}
	else if ((n / 10) == 0)
	{
		*res += 1;
		c = n + 48;
		write(1, &c, 1);
	}
	else
	{
		ft_putnbr((n / 10), res);
		c = (n % 10) + 48;
		write(1, &c, 1);
		*res += 1;
	}
	return (*res);
}

int	ft_putunsigned(unsigned int n, int *res)
{
	char	c;

	if (n == 2147483648)
		*res += write(1, "2147483648", 10);
	else if (n == 0)
	{
		*res += 1;
		write(1, "0", 1);
	}
	else if ((n / 10) == 0)
	{
		*res += 1;
		c = n + 48;
		write(1, &c, 1);
	}
	else
	{
		ft_putunsigned((n / 10), res);
		c = (n % 10) + 48;
		write(1, &c, 1);
		*res += 1;
	}
	return (*res);
}

int	ft_putnbr_base(unsigned int n, char base, int *res)
{
	char	*dicc;

	if (base == 'x')
		dicc = "0123456789abcdef";
	else if (base == 'X')
		dicc = "0123456789ABCDEF";
	if ((n / 16) == 0)
	{
		*res += 1;
		write(1, &dicc[n % 16], 1);
	}
	else
	{
		ft_putnbr_base((n / 16), base, res);
		write(1, &dicc[n % 16], 1);
		*res += 1;
	}
	return (*res);
}

int	ft_putpointer(void *ptr, int *res)
{
	unsigned long	n;
	char			*dicc;

	n = (unsigned long)ptr;
	dicc = "0123456789abcdef";
	if ((n / 16) == 0)
	{
		if (write(1, "0x", 2) == -1)
			return (-1);
		if (write(1, &dicc[n % 16], 1) == -1)
			return (-1);
		*res += 3;
	}
	else
	{
		ft_putpointer((void *)(n / 16), res);
		if (write(1, &dicc[n % 16], 1) == -1)
			return (-1);
		*res += 1;
	}
	return (*res);
}

int	ft_putstr(char *str, int *res)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			if ((write(1, &str[i], 1)) == -1)
				return (-1);
			i++;
			*res += 1;
		}
	}
	else
	{
		write(1, "(null)", 6);
		*res += 6;
		return (6);
	}
	return (i);
}
