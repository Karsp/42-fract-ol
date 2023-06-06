/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 01:04:14 by daviles-          #+#    #+#             */
/*   Updated: 2023/06/06 17:29:02 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_fractol.h"

int	ismandelbrot2(int n, double Z_re, double Z_im, double c_im, double c_re)
{
	double Z_re2;
    double Z_im2;

	while (n++ < MAX_ITERATION)
	{
		Z_re2 = Z_re * Z_re;
		Z_im2 = Z_im * Z_im;
		if(Z_re2 + Z_im2 > 4)
			return (0);
		Z_im = 2*Z_re*Z_im + c_im;
		Z_re = Z_re2 - Z_im2 + c_re;
	}
	return (1);
}

int	ismandelbrot(t_data *data, double c_im, double c_re)
{
	double	z_re;
    double	z_im;
	double	z_re2;
    double	z_im2;
	double	tmp;
	int		i;

	z_re = c_re;
	z_im = c_im;
	i = 0;
	while (i < MAX_ITERATION)
	{
		z_re2 = z_re * z_re;
		z_im2 = z_im * z_im;
		if((z_re2 + z_im2) > 4)
		{
			data->iter = i;
			return (0);
		}
		tmp = 2 * z_re * z_im + c_im;
//		z_im = 2 * z_re * z_im + c_im;
		z_re = z_re2 - z_im2 + c_re;
		z_im = tmp;
		i++;
	}
	data->iter = i;
	return (1);
}

int	generate_fractal(t_data *data)
{
	double c_im;
	double c_re;
	unsigned y;
	unsigned x;

	y = 0;
	while (y++ < HEIGHT)
	{
		x = 0;
		c_im = data->max_im + ((double)y *
				(data->min_im - data->max_im) / HEIGHT);
   	 while (x++ < WIDTH)
   	 {
        c_re = data->min_re + ((double)x *
				(data->max_re - data->min_re) / WIDTH);
        if (ismandelbrot(data, c_im, c_re))
			img_pix_put(&data->img, x, y, 0xFF0000);
//		else
//			img_pix_put(&data->img, x, y, make_color(data));
    }
}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}

int	generate_fractal2(t_data *data)
{
	/*set the area defining the four corners */
	double MinRe = -2.0;
	double MaxRe = 1.0;
	double MinIm = -1.2;
	double MaxIm = MinIm+(MaxRe-MinRe)*HEIGHT/WIDTH;
	double c_im;
	double c_re;
	double Z_re;
	double Z_im;
	unsigned y;
	unsigned x;
	unsigned n;

	y = 0;
	while (y++ < HEIGHT)
	{
		x = 0;
		c_im = MaxIm - y * (MaxIm-MinIm)/(HEIGHT-1);
   	 while (x++ < WIDTH)
   	 {
        c_re = MinRe + x * (MaxRe-MinRe)/(WIDTH-1);
        Z_re = c_re;
		Z_im = c_im;
		n = 0;
        if (ismandelbrot(data, c_im, c_re))
			img_pix_put(&data->img, x, y, 0xFF0000);
//		else
//			my_img_pix_put(&data->img, x, y, 0x0000FF);
    }
}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
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
	generate_fractal(&data);
	/* Setup hooks */
	mlx_key_hook(data.win_ptr, &handle_keys, &data);
	mlx_loop(data.mlx_ptr);
	/* we will exit the loop if there's no window left, and execute this code */
	free(data.mlx_ptr);
}

