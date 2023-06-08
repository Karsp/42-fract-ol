/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 01:07:44 by daviles-          #+#    #+#             */
/*   Updated: 2023/06/08 03:50:45 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_fractol.h"

int	isjulia(t_data *data, double z_im, double z_re)
{
	double	tmp;
	int		i;

	i = 0;
	while (i < (MAX_ITERATION + data->res_shift))
	{
		if (((z_re * z_re) + (z_im * z_im)) > 4)
		{
			data->iter = i;
			return (0);
		}
		tmp = 2 * z_re * z_im + data->julia_kx;
		z_re = (z_re * z_re) - (z_im * z_im) + data->julia_ky;
		z_im = tmp;
		i++;
	}
	data->iter = i;
	return (1);
}

void	generate_julia(t_data *data)
{
	double			z_im;
	double			z_re;
	unsigned int	y;
	unsigned int	x;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		z_im = data->max_im + ((double)y * (data->min_im
					- data->max_im) / HEIGHT);
		while (++x < WIDTH)
		{
			z_re = data->min_re + ((double)x * (data->max_re
						- data->min_re) / WIDTH);
			if (isjulia(data, z_im, z_re))
				img_pix_put(&data->img, x, y, 0x000000);
			else
				img_pix_put(&data->img, x, y, make_color(data));
		}
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.mlx_img, 0, 0);
}

void	new_julia(int x, int y, t_data *data)
{
	data->julia_ky = data->max_im + ((double)y * (data->min_im
					- data->max_im) / HEIGHT);
	data->julia_kx = data->min_re + ((double)x * (data->max_re
						- data->min_re) / WIDTH);
	ft_printf("New Julia Z value: %d  %d\n", x, y);
}
