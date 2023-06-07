/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 01:04:14 by daviles-          #+#    #+#             */
/*   Updated: 2023/06/07 02:20:38 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_fractol.h"

int	ismandelbrot(t_data *data, double c_im, double c_re)
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
		if(((z_re * z_re) + (z_im * z_im)) > 4)
		{
			data->iter = i;
			return (0);
		}
		tmp = 2 * z_re * z_im + c_im;
		z_re = (z_re * z_re) - (z_im * z_im) + c_re;
		z_im = tmp;
		i++;
	}
	data->iter = i;
	return (1);
}

void	generate_mandelbrot(t_data *data)
{
	double c_im;
	double c_re;
	unsigned y;
	unsigned x;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		c_im = data->max_im + ((double)y *
				(data->min_im - data->max_im) / HEIGHT);
   	 while (++x < WIDTH)
   	 {
        c_re = data->min_re + ((double)x *
				(data->max_re - data->min_re) / WIDTH);
        if (ismandelbrot(data, c_im, c_re))
			img_pix_put(&data->img, x, y, 0x000000);
		else
		{
		//	img_pix_put(&data->img, x, y, get_light(data->iter, data));
			img_pix_put(&data->img, x, y, make_color(data));
		}
    }
}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
}

int	main(void)
{
	t_data	data;

	data = clean_init();
	set_minmaxnum(&data);
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);

	data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "Let's Fract-ol");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WIDTH, HEIGHT);
	if (!data.img.mlx_img)
	{
		ft_close(&data);
		printf("MLX image creation error.\n");
		return (MLX_ERROR);
	}
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, \
							&data.img.ln_len, &data.img.endian);
	/* Generate fractal*/
	mlx_loop_hook(data.mlx_ptr, &generate_fractal, &data);
	/* Setup hooks */
	handle_events(&data);
	mlx_loop(data.mlx_ptr);
	free(data.mlx_ptr);
}

