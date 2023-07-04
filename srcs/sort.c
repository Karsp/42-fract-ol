/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:07:39 by daviles-          #+#    #+#             */
/*   Updated: 2023/06/21 16:36:04 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_fractol.h"

int	check_arg(char **argv)
{
	ft_striteri(argv[1], my_tolower);
	if (!ft_strncmp(argv[1], "mandelbrot", 10))
		return (1);
	else if (!ft_strncmp(argv[1], "julia", 5))
		return (2);
	else if (!ft_strncmp(argv[1], "burning_ship", 12) || !ft_strncmp(argv[1],
			"burningship", 12))
		return (3);
	else if (!ft_strncmp(argv[1], "1", 1))
		return (1);
	else if (!ft_strncmp(argv[1], "2", 1))
		return (2);
	else if (!ft_strncmp(argv[1], "3", 1))
		return (3);
	else
		return (0);
}

void	check_move(t_data *data, int keysym)
{
	if (data->set == 3)
	{
		if (keysym == A_LEFT || keysym == A)
			move_bonus(data, 'L');
		if (keysym == A_RIGHT || keysym == D)
			move_bonus(data, 'R');
		if (keysym == A_DOWN || keysym == S)
			move_bonus(data, 'D');
		if (keysym == A_UP || keysym == W)
			move_bonus(data, 'U');
	}
	else
	{
		if (keysym == A_LEFT || keysym == A)
			move(data, 'L');
		if (keysym == A_RIGHT || keysym == D)
			move(data, 'R');
		if (keysym == A_DOWN || keysym == S)
			move(data, 'D');
		if (keysym == A_UP || keysym == W)
			move(data, 'U');
	}
}

void	mouse_zoom_bonus(t_data *data, double zoom, int x, int y)
{
	double	normalized_radius_re;
	double	normalized_radius_im;
	double	delta_x;
	double	delta_y;

	data->norm_x = data->max_re + ((double)(WIDTH - x) *(data->min_re
				- data->max_re) / WIDTH);
	data->norm_y = data->max_im + ((double)(HEIGHT - y) *(data->min_im
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
