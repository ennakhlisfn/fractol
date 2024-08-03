/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_img_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sennakhl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 20:14:37 by sennakhl          #+#    #+#             */
/*   Updated: 2024/05/23 12:59:27 by sennakhl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	img_pixel_put(int x, int y, t_fractol *frac, int color)
{
	int	offset;

	offset = (y * frac->ll) + (x * (frac->bpp / 8));
	*(unsigned int *)(frac->pxl + offset) = color;
}

void	pixel_handler_mandelbrot(t_fractol *frac, int y, int x)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.r = (frac->max_x - frac->min_x) * x / WIDTH + frac->min_x;
	z.r += frac->shift_x;
	z.i = (frac->max_y - frac->min_y) * y / HEIGHT + frac->min_y;
	z.i += frac->shift_y;
	c = z;
	while (i < frac->iter)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.r * z.r) + (z.i * z.i) > 4)
		{
			color = (frac->c2 - frac->c1) * i / frac->iter + frac->c1;
			img_pixel_put(x, y, frac, color);
			return ;
		}
		i++;
	}
	img_pixel_put(x, y, frac, frac->c3);
}

void	pixel_handler_multibrot(t_fractol *frac, int y, int x)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.r = (frac->max_x - frac->min_x) * x / WIDTH + frac->min_x;
	z.r += frac->shift_x;
	z.i = (frac->max_y - frac->min_y) * y / HEIGHT + frac->min_y;
	z.i += frac->shift_y;
	c = z;
	while (i < frac->iter)
	{
		z = square_complex(z);
		z = square_complex(z);
		z = sum_complex(square_complex(z), c);
		if ((z.r * z.r) + (z.i * z.i) > 4)
		{
			color = (frac->c2 - frac->c1) * i / frac->iter + frac->c1;
			img_pixel_put(x, y, frac, color);
			return ;
		}
		i++;
	}
	img_pixel_put(x, y, frac, frac->c3);
}

void	pixel_handler_julia(t_fractol *frac, int y, int x)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.r = (frac->max_x - frac->min_x) * x / WIDTH + frac->min_x;
	z.r += frac->shift_x;
	z.i = (frac->max_y - frac->min_y) * y / HEIGHT + frac->min_y;
	z.i += frac->shift_y;
	c.r = frac->julia_x;
	c.i = frac->julia_y;
	while (i < frac->iter)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.r * z.r) + (z.i * z.i) > 4)
		{
			color = (frac->c2 - frac->c1) * i / frac->iter + frac->c1;
			img_pixel_put(x, y, frac, color);
			return ;
		}
		i++;
	}
	img_pixel_put(x, y, frac, frac->c3);
}

void	fractal_render(t_fractol *frac)
{
	int	x;
	int	y;
	int	set;

	set = ft_strcmp(frac->name, "mandelbrot");
	y = 0;
	while (y / HEIGHT < 1)
	{
		x = 0;
		while (x / WIDTH < 1)
		{
			if (set < 0)
				pixel_handler_julia(frac, y, x);
			else if (set > 0)
				pixel_handler_multibrot(frac, y, x);
			else
				pixel_handler_mandelbrot(frac, y, x);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(frac->conect, frac->new_win, frac->img, 0, 0);
}
