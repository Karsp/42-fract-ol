/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setInit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:07:07 by daviles-          #+#    #+#             */
/*   Updated: 2023/06/21 20:38:15 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_fractol.h"

t_data	clean_init(void)
{
	t_data	data;

	data.mlx_ptr = NULL;
	data.win_ptr = NULL;
	data.min_re = 0;
	data.max_re = 0;
	data.min_im = 0;
	data.max_im = 0;
	data.iter = 0;
	data.color_shift = 1;
	data.set = 0;
	data.center_im = 0;
	data.center_re = 0;
	data.norm_x = 0;
	data.norm_y = 0;
	data.julia_kx = 0;
	data.julia_ky = 0;
	data.julia_set = 0;
	data.mouse_move = 0;
	data.img.mlx_img = ft_calloc(1, sizeof(t_img));
	data.color = ft_calloc(1, sizeof(t_color));
	data.res_shift = 0;
	return (data);
}

void	set_minmaxnum(t_data *data)
{
	data->min_re = -2.0;
	data->max_re = 1.2;
	data->min_im = -1.2;
	data->max_im = data->min_im + (data->max_re - data->min_re)
		* HEIGHT / WIDTH;
}

int	data_init(t_data *data)
{
	set_minmaxnum(data);
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (MLX_ERROR);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "Fract-ol");
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		return (MLX_ERROR);
	}
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	if (!data->img.mlx_img)
	{
		ft_close(data);
		ft_printf("MLX image creation error.\n");
		return (MLX_ERROR);
	}
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp, \
							&data->img.ln_len, &data->img.endian);
	return (1);
}

void	print_help(t_data *data)
{
	if (data->set == 1)
	{
		ft_printf("##  Running Mandelbrot Set  ##\n");
		ft_printf("%s%s%s%s", F_KEYS1, F_KEYS2, F_KEYS3, M_KEYS1);
	}
	if (data->set == 2)
	{
		ft_printf("##  Running Julia Set  ##\n");
		ft_printf("%s%s%s", F_KEYS1, F_KEYS2, F_KEYS3);
		ft_printf("%s%s%s", J_KEYS1, J_KEYS2, J_KEYS3);
	}
	if (data->set == 3)
	{
		ft_printf("##  Running Burning Ship  ##\n");
		ft_printf("%s%s%s", F_KEYS1, F_KEYS2, F_KEYS3);
	}
}
