/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 20:54:25 by daviles-          #+#    #+#             */
/*   Updated: 2023/04/06 19:21:18 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"
//To each character of the string ’s’, apply the function ’f’ giving as 
//parameters the index of each character within ’s’ and the address of the 
//character itself character, which can be modified if necessary.

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	c;

	c = 0;
	while (s[c] != '\0')
	{
		f(c, &s[c]);
		c++;
	}
}
/*
void	my_toupper(unsigned int c, char *s)
{
	char	*str;

	str = s;
	if (*str >= 97 && *str <= 122)
		*str -= 32;
}

int	main(void)
{
	char	str[] = "Tiempo de valientes.";
	
	ft_striteri(str, my_toupper);
	printf("%s\n", str);
	return (0);
}
*/
