/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sennakhl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:38:37 by sennakhl          #+#    #+#             */
/*   Updated: 2024/05/25 10:45:57 by sennakhl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	ft_check_arg_error(int arc, char **arv)
{
	if (arc != 2 && arc != 4)
		arg_error();
	if (arc == 2 && ft_strcmp(arv[1], "mandelbrot"))
	{
		if (ft_strcmp(arv[1], "multibrot"))
			arg_error();
	}
	if (arc == 4 && ft_strcmp(arv[1], "julia"))
		arg_error();
	if (arc == 4 && (!ft_isdouble(arv[2]) || !ft_isdouble(arv[3])))
		arg_error();
}

void	init_frac(t_fractol *frac, char **arv)
{
	frac->name = arv[1];
	if (!ft_strcmp(arv[1], "julia"))
	{
		frac->julia_x = atod(arv[2]);
		frac->julia_y = atod(arv[3]);
	}
	frac->shift_x = 0;
	frac->shift_y = 0;
	frac->min_x = -2;
	frac->max_x = 2;
	frac->min_y = 2;
	frac->max_y = -2;
	frac->iter = 30;
	frac->c1 = BLACK;
	frac->c2 = BLUE;
	frac->c3 = WHITE;
}

int	main(int arc, char *arv[])
{
	t_fractol	*frac;

	ft_check_arg_error(arc, arv);
	frac = (t_fractol *)malloc(sizeof(t_fractol));
	frac->conect = mlx_init();
	if (!frac->conect)
		mlx_error(frac);
	init_frac(frac, arv);
	frac->new_win = mlx_new_window(frac->conect, WIDTH, HEIGHT, arv[1]);
	if (!frac->new_win)
		mlx_error(frac);
	frac->img = mlx_new_image(frac->conect, WIDTH, HEIGHT);
	if (!frac->img)
		mlx_error(frac);
	frac->pxl = mlx_get_data_addr(frac->img, &frac->bpp, &frac->ll, &frac->end);
	fractal_render(frac);
	mlx_put_image_to_window(frac->conect, frac->new_win, frac->img, 0, 0);
	init_mlx_hook(frac);
	mlx_loop(frac->conect);
	return (0);
}
