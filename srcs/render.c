/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:53:11 by daviles-          #+#    #+#             */
/*   Updated: 2023/06/21 17:27:43 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_fractol.h"

int	generate_fractal(t_data *data)
{
	if (data->set == 1)
		generate_mandelbrot(data);
	if (data->set == 2)
		generate_julia(data);
	if (data->set == 3)
		generate_burnship(data);
	return (1);
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->ln_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

int	make_color(t_data *data)
{
	int	color_value;

	color_value = data->iter * 15;
	data->color->r = get_r(color_value);
	data->color->g = get_g(color_value);
	data->color->b = get_b(color_value);
	apply_shift(data);
	return (create_trgb(0, data->color->r, data->color->g, data->color->b));
}

void	shift_color(t_data *data)
{
	data->color_shift += 1;
	if (data->color_shift > 5)
		data->color_shift = 1;
}

void	apply_shift(t_data *data)
{
	if (data->color_shift == 1)
	{
		data->color->r += 150;
		data->color->b += 10;
	}
	else if (data->color_shift == 2)
	{
		data->color->r += 70;
		data->color->b += 70;
	}
	else if (data->color_shift == 3)
		data->color->g += 75;
	else if (data->color_shift == 4)
		data->color->b += 140;
	else
	{
		data->color->b = 75;
		data->color->g += 75;
	}
}
