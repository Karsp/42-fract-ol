/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:25:48 by daviles-          #+#    #+#             */
/*   Updated: 2023/06/08 03:52:01 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_fractol.h"

void	ft_close(t_data *data)
{
	if (data->img.mlx_img)
		mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->color)
		free(data->color);
	printf("\nExit program.");
	exit(0);
}

int	handle_events(t_data *data)
{
	mlx_key_hook(data->win_ptr, &handle_keys, data);
	mlx_hook(data->win_ptr, ON_MOUSEDOWN, 0, handle_mouse, data);
	mlx_hook(data->win_ptr, ON_DESTROY, 0, (void *)ft_close, data);
	return (0);
}

int	handle_keys(int keysym, t_data *data)
{
	if (keysym == 49)
		shift_color(data);
	if (keysym == 53)
		ft_close(data);
	if (keysym == 257 || keysym == 258)
	{
		if (data->res_shift < 220)
			data->res_shift += 10;
		else
			data->res_shift = 10;
		ft_printf("Resolution: %d\n", data->res_shift + MAX_ITERATION);
	}
	if (keysym == 123 || keysym == 0)
		move(data, 'L');
	if (keysym == 124 || keysym == 2)
		move(data, 'R');
	if (keysym == 125 || keysym == 1)
		move(data, 'D');
	if (keysym == 126 || keysym == 13)
		move(data, 'U');
//	printf("Keypress: %d\n", keysym);
	return (0);
}

int	handle_mouse(int keysym, int x, int y, t_data *data)
{
	if (keysym == 4)
		mouse_zoom(data, 0.9, x, y);
	if (keysym == 5)
		mouse_zoom(data, 1.1, x, y);
	if (keysym == 1)
		new_julia(x, y, data);
	return (0);
}
