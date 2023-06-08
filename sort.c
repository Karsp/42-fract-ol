/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:07:39 by daviles-          #+#    #+#             */
/*   Updated: 2023/06/08 01:04:17 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_fractol.h"

int	check_arg(char **argv)
{
	ft_striteri(argv[1], my_tolower);
	if (!ft_strncmp(argv[1], "mandelbrot", 10))
		return (1);
	else if (!ft_strncmp(argv[1], "julia", 5))
		return (2);
	else if (!ft_strncmp(argv[1], "1", 1))
		return (1);
	else if (!ft_strncmp(argv[1], "2", 1))
		return (2);
	else
		return (0);
}
