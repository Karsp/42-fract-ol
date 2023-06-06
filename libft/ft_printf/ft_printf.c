/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 20:43:46 by daviles-          #+#    #+#             */
/*   Updated: 2023/06/05 12:39:46 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libftprintf.h"

int	ft_putchar(char c, int *res)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	*res = *res + 1;
	return (*res);
}

int	ft_chkflag(char const *num_args, va_list *ptr, int *res)
{
	int	chk;

	chk = 0;
	if (*num_args == '%')
		chk = ft_putchar('%', res);
	else if (*num_args == '%' || *num_args == 'c')
		chk = ft_putchar(va_arg(*ptr, int), res);
	else if (*num_args == 'd' || *num_args == 'i')
		chk = ft_putnbr(va_arg(*ptr, int), res);
	else if (*num_args == 'u')
		chk = ft_putunsigned(va_arg(*ptr, unsigned int), res);
	else if (*num_args == 's')
		chk = ft_putstr(va_arg(*ptr, char *), res);
	else if (*num_args == 'x')
		chk = ft_putnbr_base(va_arg(*ptr, int), 'x', res);
	else if (*num_args == 'X')
		chk = ft_putnbr_base(va_arg(*ptr, int), 'X', res);
	else if (*num_args == 'p')
		chk = ft_putpointer(va_arg(*ptr, void *), res);
	return (chk);
}

int	ft_printf(char const *num_args, ...)
{
	va_list	ptr;
	int		res;

	res = 0;
	if (!num_args)
		return (-1);
	va_start(ptr, num_args);
	while (*num_args != '\0')
	{
		if (*num_args == '%')
		{
			++num_args;
			if (ft_chkflag(num_args, &ptr, &res) == -1)
				return (-1);
		}
		else
			if (ft_putchar(*num_args, &res) == -1)
				return (-1);
		++num_args;
	}
	va_end(ptr);
	return (res);
}
/*
int	main(void)
{
	int		n;
	int		res;
	int		res2;
	char	*str = "Day after tomorrow";
	char	*strwith = "One Day at half others at 100%.";
	char	c;
	int		hex;

	n = -2147483648;
	c = 'A';
	hex = -253;
	ft_printf("\n\\\\\\  Test %%c  \\\n\n");
	res = ft_printf("Var c %c. Quotes   %c\n", c, 'l'); 
	res2 = printf("Var c %c. Quotes   %c\n", c, 'l'); 
	printf("INT result FT %i\n", res);
	printf("INT result PO %i\n", res2);

	ft_printf("\n\\\\\\  Test %%s  \\\n\n");
	res = ft_printf(NULL); 
//	res2 = printf(NULL); 
	printf("FT %i\n", res);
	printf("PO %i\n", res2);

	ft_printf("\n\\\\\\  Test %%d  \\\n\n");
	res = ft_printf("Var n %d\n", n); 
	res2 = printf("Var n %d\n", n); 
	printf("FT %i\n", res);
	printf("PO %i\n", res2);

	ft_printf("\n\\\\\\  Test %%i  \\\n\n");
	res = ft_printf("Var n %i\n", n); 
	res2 = printf("Var n %i\n", n); 
	printf("FT %i\n", res);
	printf("PO %i\n", res2);

	ft_printf("\n\\\\\\  Test %%u  \\\n\n");
	res = ft_printf("Var n %u\n", n); 
	res2 = printf("Var n %u\n", n); 
	printf("FT %i\n", res);
	printf("PO %i\n", res2);

	ft_printf("\n\\\\\\  Test %%x  \\\n\n");
	res = ft_printf("Var hex %x\n", hex); 
	res2 = printf("Var hex %x\n", hex); 
	printf("FT %i\n", res);
	printf("PO %i\n", res2);

	ft_printf("\n\\\\\\  Test %%X  \\\n\n");
	res = ft_printf("Var str %X\n", hex); 
	res2 = printf("Var str %X\n", hex); 
	printf("FT %i\n", res);
	printf("PO %i\n", res2);

	ft_printf("\n\\\\\\  Test %%p  \\\n\n");
	res = ft_printf("Var &str %p\n", &str); 
	res2 = printf("Var &str %p\n", &str); 
	printf("FT %i\n", res);
	printf("PO %i\n", res2);

	ft_printf("\n\\\\\\  Test %%  \\\n\n");
	res = ft_printf("Str with %% var strwith  %s\n", strwith); 
	res2 = printf("Str with %% var strwith  %s\n", strwith); 
	printf("FT %i\n", res);
	printf("PO %i\n", res2);

	return (0);
}*/
