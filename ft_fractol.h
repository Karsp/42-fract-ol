/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 21:26:55 by daviles-          #+#    #+#             */
/*   Updated: 2023/06/06 17:26:32 by daviles-         ###   ########.fr       */
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
# define MLX_ERROR 1

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	t;
}	t_color;

typedef struct	s_img {
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
	t_color			*color;
	unsigned int	iter;
	double			min_re;
	double			max_re;
	double			min_im;
	double			max_im;
	double			center_im;
	double			center_re;
	int				color_shift;
	int				set;
	int				res;
}	t_data;

// initialization functions
void	set_minmaxnum(t_data *data);
t_data	clean_init(void);

// render and color functions
void	img_pix_put(t_img *img, int x, int y, int color);
int		create_trgb(int t, int r, int g, int b);
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);
int		make_color(t_data *data);
void	shift_color(t_data *data);
void	apply_shift(t_data *data);
void	shift_res(t_data *data);
// Mandelbrot functions
//int	ismandelbrot(int n, double Z_re, double Z_im, double c_im, double c_re);
int     ismandelbrot(t_data *data, double c_im, double c_re);
// sort / analize functions
int	generate_fractal(t_data *data);

// event handling functions:
int	handle_mouse(int keysym, void *data);
int	handle_keys(int keysym, t_data *data);
int	handle_no_event(void *data);

void	ft_close(t_data *data);

#endif
