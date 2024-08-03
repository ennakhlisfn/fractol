/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sennakhl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:22:00 by sennakhl          #+#    #+#             */
/*   Updated: 2024/05/27 11:33:27 by sennakhl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

int	key_handler(int keysym, t_fractol *frac)
{
	if (keysym == XK_ESCAPE)
		destroy(frac);
	else if (keysym == XK_P)
		frac->iter += 10;
	else if (keysym == XK_MINUS)
		frac->iter -= 10;
	fractal_render(frac);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractol *frac)
{
	(void)(x);
	(void)(y);
	if (button == 5)
	{
		frac->min_x *= 1.1;
		frac->max_x *= 1.1;
		frac->min_y *= 1.1;
		frac->max_y *= 1.1;
	}
	if (button == 4)
	{
		frac->min_x /= 1.1;
		frac->max_x /= 1.1;
		frac->min_y /= 1.1;
		frac->max_y /= 1.1;
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
