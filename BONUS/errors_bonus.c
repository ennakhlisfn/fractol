/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sennakhl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:15:04 by sennakhl          #+#    #+#             */
/*   Updated: 2024/05/22 15:18:35 by sennakhl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	mlx_error(t_fractol *frac)
{
	if (frac->new_win)
		mlx_destroy_window(frac->conect, frac->new_win);
	if (frac->conect)
		mlx_destroy_display(frac->conect);
	free(frac);
	ft_putstr_fd("problem in mlx function\n", 2);
	exit(1);
}

void	arg_error(void)
{
	ft_putstr_fd("you have to enter : mandelbrot or multibrot\n", 1);
	ft_putstr_fd("or : julia <real_number> <imagener_number>\n", 1);
	exit (0);
}
