/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setInit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:07:07 by daviles-          #+#    #+#             */
/*   Updated: 2023/06/08 03:51:58 by daviles-         ###   ########.fr       */
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
	data.julia_kx = 0;
	data.julia_ky = 0;
	data.img.mlx_img = ft_calloc(1, sizeof(t_img));
	data.color = ft_calloc(1, sizeof(t_color));
	data.res_shift = 0;
	return (data);
}

void	set_minmaxnum(t_data *data)
{
	data->min_re = -2.0;
	data->max_re = 1.0;
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
		printf("MLX image creation error.\n");
		return (MLX_ERROR);
	}
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp, \
							&data->img.ln_len, &data->img.endian);
	return (1);
}
