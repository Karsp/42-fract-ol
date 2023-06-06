#include "ft_fractol.h"



void	ft_close(m_data *data)
{
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	printf("\nExit program.");
	exit(0);
}

int	handle_no_event(void *data)
{
	/* This function needs to exist, but it is useless for the moment */
	return (0);
}

int	handle_input(int keysym, m_data *data)
{
	printf("Key %d\n", keysym);
	if (keysym == 53)
		ft_close(data);
	return (0);
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char    *pixel;

    pixel = img->addr + (y * img->ln_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

int	isMandelbrot(int n, double Z_re, double Z_im, double c_im, double c_re)
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


int	generate_fractal(t_data data)
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
        if (isMandelbrot(n, Z_re, Z_im, c_im, c_re))
			img_pix_put(&data.img, x, y, 0xFF0000);
		else
			img_pix_put(&data.img, x, y, make_color(&data));
    }
}
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img.mlx_img, 0, 0);
	return (0);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		i;
	m_data	data;
	int		imgH;
	int		imgW;

	imgW = 800;
	imgH = 600;
	i = 0;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (0);
	data.win_ptr = mlx_new_window(data.mlx_ptr, imgW, imgH,
			"My first window!");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (0);
	}
/*	mlx = mlx_init();
	if (mlx == NULL)
		return(0);
	mlx_win = mlx_new_window(mlx, imgW, imgH, "Let's Fract-ol");
	if (mlx_win == NULL)
		return(free(mlx), 0);
*/
//	img.img = mlx_new_image(mlx, imgW, imgH);
//	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.ln_len, &img.endian);

	mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
	mlx_key_hook(data.win_ptr, &handle_input, &data);

	mlx_loop(data.mlx_ptr);

	/* we will exit the loop if there's no window left, and execute this code */
	free(data.mlx_ptr);

	/*
	double	minRe;
	double	maxRe;
	double	minIm;
	double	maxIm;
	double	reFact;
	double	imFact;
	double	c_re;
	double	c_im;
	double	z_re;
	double	z_im;
	double	z_re2;
	double	z_im2;
	int		x;
	int		y;
	int		maxIter;
	int		iter;
	int		isMan;

	maxIter = 60;
	x = 0;
	y = 0;
	minRe = -2.0;
	maxRe = 1.0;
	minIm = -1.2;
	maxIm = minIm + (maxRe - minRe) * imgH / imgW;
	reFact = (maxRe - minRe) / (imgW - 1);
	imFact = (maxIm - minIm) / (imgH - 1);
	while (y < imgH)
	{
		c_im = maxIm - y * imFact;
		while (x < imgW)
		{
			c_re = maxRe + x * reFact;
			z_re = c_re;
			z_im = c_im;
			iter = 0;
			isMan = 1;
			while (iter < maxIter && isMan)
			{
				z_re2 = z_re * z_re;
				z_im2 = z_im * z_im;
				if (z_re2 + z_im2 > 4)
				{
					ft_imgdata(&img, x, y, 0xFF000000);
					mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
					isMan = 0;
				}
				z_im = 2 * z_re * z_im + c_im;
				z_re = z_re2 - z_im2 + c_re;
				iter++;
			}
			if (isMan)
			{
				ft_imgdata(&img, x, y, 0x00FF0000);
				mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
			}
			x++;
		}
		x = 0;
		y++;
	}

	mlx_loop(mlx);
	mlx_destroy_display (mlx);
	free (mlx);
	*/

}
