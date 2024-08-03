/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sennakhl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 20:43:20 by sennakhl          #+#    #+#             */
/*   Updated: 2024/05/22 15:18:35 by sennakhl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	res;

	res.r = z1.r + z2.r;
	res.i = z1.i + z2.i;
	return (res);
}

t_complex	square_complex(t_complex z)
{
	t_complex	res;

	res.i = 2 * z.i * z.r;
	res.r = z.r * z.r - z.i * z.i;
	return (res);
}
