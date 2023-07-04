/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:39:02 by daviles-          #+#    #+#             */
/*   Updated: 2023/06/15 21:38:00 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_fractol.h"

int	isburnship(t_data *data, double c_im, double c_re)
{
	double	z_re;
	double	z_im;
	double	tmp;
	int		i;

	z_re = c_re;
	z_im = c_im;
	i = 0;
	while (i < (MAX_ITERATION + data->res_shift))
	{
		if (((z_re * z_re) + (z_im * z_im)) > 4)
		{
			data->iter = i;
			return (0);
		}
		z_im = fabs(z_im);
		z_re = fabs(z_re);
		tmp = 2 * z_re * z_im + c_im;
		z_re = (z_re * z_re) - (z_im * z_im) + c_re;
		z_im = tmp;
		i++;
	}
	data->iter = i;
	return (1);
}

void	generate_burnship(t_data *data)
{
	double			c_im;
	double			c_re;
	unsigned int	y;
	unsigned int	x;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		c_im = data->min_im - ((double)y * (data->min_im
					- data->max_im) / HEIGHT);
		while (++x < WIDTH)
		{
			c_re = data->min_re + ((double)x * (data->max_re
						- data->min_re) / WIDTH);
			if (isburnship(data, c_im, c_re))
				img_pix_put(&data->img, x, y, 0x000000);
			else
				img_pix_put(&data->img, x, y, make_color(data));
		}
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.mlx_img, 0, 0);
}
