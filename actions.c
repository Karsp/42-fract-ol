/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 01:55:55 by daviles-          #+#    #+#             */
/*   Updated: 2023/06/08 01:00:11 by daviles-         ###   ########.fr       */
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

void	mouse_zoom(t_data *data, double zoom, int x, int y)
{
	(void)x;
	(void)y;
	data->center_re = data->min_re - data->max_re;
	data->center_im = data->max_im - data->min_im;
	data->max_re = data->max_re + (data->center_re - zoom
			* data->center_re) / 2;
	data->min_re = data->max_re + zoom * data->center_re;
	data->min_im = data->min_im + (data->center_im - zoom
			* data->center_im) / 2;
	data->max_im = data->min_im + zoom * data->center_im;
	return ;
}
