/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 21:26:55 by daviles-          #+#    #+#             */
/*   Updated: 2023/06/08 03:11:40 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# include  "./mlx/mlx.h"
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include "./libft/libft.h"
# define HEIGHT 600
# define WIDTH 800
# define MAX_ITERATION 30
# define ARG_MESS "Please write the name or number of the choosen fractal.\n"
# define F_OPTIONS " 1-Mandelbrot\n 2-Julia\n"
# define MLX_ERROR 1

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	t;
}	t_color;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		ln_len;
	int		endian;
}				t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_color	*color;
	int		iter;
	double	min_re;
	double	max_re;
	double	min_im;
	double	max_im;
	double	center_im;
	double	center_re;
	double	julia_kx;
	double	julia_ky;
	int		color_shift;
	int		set;
	int		res_shift;
}	t_data;

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

// initialization functions
t_data	clean_init(void);
int		data_init(t_data *data);
void	set_minmaxnum(t_data *data);
// render and color functions
int		generate_fractal(t_data *data);
void	img_pix_put(t_img *img, int x, int y, int color);
int		create_trgb(int t, int r, int g, int b);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);
int		make_color(t_data *data);
void	shift_color(t_data *data);
void	apply_shift(t_data *data);
void	shift_resolution(t_data *data);
// actions
void	move(t_data	*data, char key);
void	mouse_zoom(t_data *data, double zoom, int x, int y);
void	ft_close(t_data *data);
// Mandelbrot functions
int		ismandelbrot(t_data *data, double c_im, double c_re);
void	generate_mandelbrot(t_data *data);
// Julia functions
int		isjulia(t_data *data, double z_im, double z_re);
void	generate_julia(t_data *data);
void	new_julia(int x, int y, t_data *data);
// sort / analize functions
int		check_arg(char **argva);
// event handling functions:
int		handle_mouse(int keysym, int x, int y, t_data *data);
int		handle_keys(int keysym, t_data *data);
int		handle_events(t_data *data);

#endif
