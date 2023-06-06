/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:25:48 by daviles-          #+#    #+#             */
/*   Updated: 2023/06/06 17:14:31 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_fractol.h"


void	ft_close(t_data *data)
{
	if (data->img.mlx_img)
	{
		mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	}
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	printf("\nExit program.");
	exit(0);
}

int	handle_no_event(void *data)
{
	(void)data;
	return (0);
}


int	handle_keys(int keysym, t_data *data)
{
	if (keysym == 53)
		ft_close(data);
	if (keysym == 257)
		shift_res(data);
	printf("Keypress: %d\n", keysym);
	return (0);
}

int	handle_mouse(int keysym, void *data)
{
	printf("Keyrelease: %d\n", keysym);
	(void)data;
	return (0);
}
