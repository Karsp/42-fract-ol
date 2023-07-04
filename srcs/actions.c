/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 01:55:55 by daviles-          #+#    #+#             */
/*   Updated: 2023/06/21 15:48:21 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_fractol.h"

void	move(t_data	*data, char key)
{
	data->center_re = data->min_re - data->max_re;
	data->center_im = data->min_im - data->max_im;
	if (key == 'U')
	{
		data->min_im -= data->center_im * 0.1;
		data->max_im -= data->center_im * 0.1;
	}
	if (key == 'D')
	{
		data->min_im += data->center_im * 0.1;
		data->max_im += data->center_im * 0.1;
	}
	if (key == 'R')
	{
		data->min_re -= data->center_re * 0.1;
		data->max_re -= data->center_re * 0.1;
	}
	if (key == 'L')
	{
		data->min_re += data->center_re * 0.1;
		data->max_re += data->center_re * 0.1;
	}
	return ;
}

void	move_bonus(t_data	*data, char key)
{
	data->center_re = data->min_re - data->max_re;
	data->center_im = data->min_im - data->max_im;
	if (key == 'U')
	{
		data->min_im += data->center_im * 0.1;
		data->max_im += data->center_im * 0.1;
	}
	if (key == 'D')
	{
		data->min_im -= data->center_im * 0.1;
		data->max_im -= data->center_im * 0.1;
	}
	if (key == 'R')
	{
		data->min_re -= data->center_re * 0.1;
		data->max_re -= data->center_re * 0.1;
	}
	if (key == 'L')
	{
		data->min_re += data->center_re * 0.1;
		data->max_re += data->center_re * 0.1;
	}
	return ;
}

void	mouse_zoom(t_data *data, double zoom, int x, int y)
{
	double	normalized_radius_re;
	double	normalized_radius_im;
	double	delta_x;
	double	delta_y;

	data->norm_x = data->max_re + ((double)(WIDTH - x) *(data->min_re
				- data->max_re) / WIDTH);
	data->norm_y = data->max_im + ((double)y * (data->min_im
				- data->max_im) / HEIGHT);
	data->center_im = ((data->max_im - data->min_im) / 2) + data->min_im;
	data->center_re = ((data->max_re - data->min_re) / 2) + data->min_re;
	normalized_radius_re = data->max_re - data->center_re;
	normalized_radius_im = data->max_im - data->center_im;
	delta_x = (data->norm_x - data->center_re);
	delta_y = (data->norm_y - data->center_im);
	normalized_radius_re *= zoom;
	normalized_radius_im *= zoom;
	delta_x *= zoom;
	delta_y *= zoom;
	data->center_re = data->norm_x - delta_x;
	data->center_im = data->norm_y - delta_y;
	data->max_re = normalized_radius_re + data->center_re;
	data->min_re = data->center_re - normalized_radius_re;
	data->max_im = normalized_radius_im + data->center_im;
	data->min_im = data->center_im - normalized_radius_im;
}

void	mouse_move_shift(t_data *data)
{
	if (data->mouse_move == 1)
		data->mouse_move = 0;
	else if (data->mouse_move == 0)
		data->mouse_move = 1;
}
