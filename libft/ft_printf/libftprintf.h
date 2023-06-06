/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:43:55 by daviles-          #+#    #+#             */
/*   Updated: 2023/06/05 12:41:14 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include<stdarg.h>
# include<stdio.h>
# include<unistd.h>
# include<stdlib.h>

int	ft_printf(char const *args, ...);
int	ft_putchar(char c, int *res);
int	ft_putstr(char *str, int *res);
int	ft_putnbr(int n, int *res);
int	ft_putnbr_base(unsigned int n, char base, int *res);
int	ft_putunsigned(unsigned int n, int *res);
int	ft_putpointer(void *ptr, int *res);

#endif
