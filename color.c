/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:30:48 by daviles-          #+#    #+#             */
/*   Updated: 2023/06/07 01:11:49 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_fractol.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_light(int i, t_data *data)
{
	int	percent;
	int	max_iter;

	max_iter = MAX_ITERATION + data->res_shift;
	if (i <= (max_iter / 2 - 1))
	{
		percent = (i * 100) / (max_iter / 2);
		data->color->r = 255;
		data->color->g = 255 * (percent / 100);
		data->color->b = 255 * (percent / 100);
	}
	else
	{
		percent = (i * 100) / (max_iter);
		data->color->r = 255 * (percent / 100);
		data->color->g = 255;
		data->color->b = 255;
	}
	return (create_trgb(0, data->color->r, data->color->g, data->color->b));
}

int	get_r(int color_value)
{
	if (color_value >= 0 && color_value <= 255)
		return (255);
	else if (color_value > 255 && color_value <= 510)
		return (255 - (color_value - 255));
	else if (color_value > 510 && color_value <= 1020)
		return (0);
	else if (color_value > 1020 && color_value <= 1275)
		return (color_value - 1020);
	else
		return (255);
}

int	get_g(int color_value)
{
	if (color_value >= 0 && color_value <= 255)
		return (color_value);
	else if (color_value > 255 && color_value <= 765)
		return (255);
	else if (color_value > 765 && color_value <= 1020)
		return (255 - (color_value - 765));
	else if (color_value > 1020 && color_value <= 1275)
		return (0);
	else
		return (255);
}

int	get_b(int color_value)
{
	if (color_value >= 0 && color_value <= 510)
		return (0);
	if (color_value > 510 && color_value <= 765)
		return (color_value - 510);
	else
		return (255);
}
