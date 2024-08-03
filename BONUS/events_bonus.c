/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sennakhl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:22:00 by sennakhl          #+#    #+#             */
/*   Updated: 2024/05/27 11:44:05 by sennakhl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	destroy(t_fractol *frac)
{
	mlx_destroy_image(frac->conect, frac->img);
	mlx_destroy_window(frac->conect, frac->new_win);
	mlx_destroy_display(frac->conect);
	free(frac->conect);
	free(frac);
	exit (0);
	return (0);
}

void	c(t_fractol *frac, int key)
{
	if (key == XK_1)
	{
		frac->c1 = BLACK;
		frac->c2 = BLUE;
		frac->c3 = WHITE;
	}
	if (key == XK_2)
	{
		frac->c1 = 0xFFE4CF;
		frac->c2 = 0xFF5BAE;
		frac->c3 = 0xE72929;
	}
	if (key == XK_3)
	{
		frac->c1 = 0xFFF5E0;
		frac->c2 = 0x8DECB4;
		frac->c3 = 0x141E46;
	}
	if (key == XK_4)
	{
		frac->c1 = 0xFFAF45;
		frac->c2 = GOLD;
		frac->c3 = 0xFAF6F0;
	}
}

int	key_handler(int keysym, t_fractol *frac)
{
	if (keysym == XK_ESCAPE)
		destroy(frac);
	else if (keysym == XK_LEFT)
		frac->shift_x -= 0.1 * (frac->max_x - frac->min_x);
	else if (keysym == XK_RIGHT)
		frac->shift_x += 0.1 * (frac->max_x - frac->min_x);
	else if (keysym == XK_UP)
		frac->shift_y += 0.1 * (frac->min_y - frac->max_y);
	else if (keysym == XK_DOWN)
		frac->shift_y -= 0.1 * (frac->min_y - frac->max_y);
	else if (keysym == XK_P)
		frac->iter += 10;
	else if (keysym == XK_MINUS)
		frac->iter -= 10;
	else
		c(frac, keysym);
	fractal_render(frac);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractol *frac)
{
	t_complex	c;

	c.r = ((frac->max_x - frac->min_x) * x / WIDTH + frac->min_x);
	c.i = ((frac->max_y - frac->min_y) * y / HEIGHT + frac->min_y);
	if (button == 4 && frac->max_x - frac->min_x <= 0.000009)
		return (0);
	if (button == 5)
	{
		frac->min_x += (frac->min_x - c.r) / 20;
		frac->max_x += (frac->max_x - c.r) / 20;
		frac->min_y += (frac->min_y - c.i) / 20;
		frac->max_y += (frac->max_y - c.i) / 20;
	}
	if (button == 4)
	{
		frac->max_x -= (frac->max_x - c.r) / 20;
		frac->min_x -= (frac->min_x - c.r) / 20;
		frac->max_y -= (frac->max_y - c.i) / 20;
		frac->min_y -= (frac->min_y - c.i) / 20;
	}
	fractal_render(frac);
	return (0);
}

void	init_mlx_hook(t_fractol *frac)
{
	mlx_hook(frac->new_win, KeyPress, KeyPressMask, key_handler, frac);
	mlx_hook(frac->new_win, ButtonPress, ButtonPressMask, mouse_handler, frac);
	mlx_hook(frac->new_win, DestroyNotify, StructureNotifyMask, destroy, frac);
}
