/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 01:04:14 by daviles-          #+#    #+#             */
/*   Updated: 2023/06/08 00:28:05 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_fractol.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 1)
		printf("Argument missing.\n%s%s", ARG_MESS, F_OPTIONS);
	else if (argc >= 3)
		ft_printf("Too many arguments.\n%s%s", ARG_MESS, F_OPTIONS);
	else if (argc == 2)
	{
		if (check_arg(argv))
		{
			data = clean_init();
			data.set = check_arg(argv);
			data_init(&data);
			mlx_loop_hook(data.mlx_ptr, &generate_fractal, &data);
			handle_events(&data);
			mlx_loop(data.mlx_ptr);
			free(data.mlx_ptr);
		}
		else
			ft_printf("Check argument.\n%s%s", ARG_MESS, F_OPTIONS);
	}
	system("leaks fractol");
	return (0);
}
