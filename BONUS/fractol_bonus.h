/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sennakhl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:16:42 by sennakhl          #+#    #+#             */
/*   Updated: 2024/05/25 17:52:56 by sennakhl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

//#include "minilibx-linux/mlx.h"
# include <errno.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <X11/X.h>

# define XK_LEFT		0xff51
# define XK_UP			0xff52
# define XK_RIGHT		0xff53
# define XK_DOWN		0xff54
# define XK_MINUS		0x002d
# define XK_P			0x0070
# define XK_1			0x0031
# define XK_2			0x0032
# define XK_3			0x0033
# define XK_4			0x0034
# define XK_5			0x0035
# define XK_6			0x0036
# define XK_ESCAPE		0xff1b

# define WIDTH			1000
# define HEIGHT			1000

# define BLACK			0x000000
# define WHITE			0xFFFFFF
# define RED			0xFF0000
# define GREEN			0x00FF00
# define BLUE			0x0000FF
# define YELLOW			0xFFFF00
# define CYAN			0x00FFFF
# define MAGENTA		0xFF00FF
# define ORANGE			0xFFA500
# define PURPLE			0x800080
# define PINK			0xFFC0CB
# define GRAY			0x808080
# define BROWN			0xA52A2A
# define GOLD			0xFFD700
# define SILVER			0xC0C0C0
# define DARK_GREEN		0x006400
# define DARK_BLUE		0x00008B
# define DARK_RED		0x8B0000
# define DARK_GRAY		0xA9A9A9
# define LIGHT_GRAY		0xD3D3D3
# define MAROON			0x800000
# define NAVY			0x000080
# define OLIVE			0x808000
# define TEAL			0x008080
# define DARK_CYAN		0x008B8B
# define DARK_MAGENTA	0x8B008B

typedef struct s_complex
{
	double	r;
	double	i;
}	t_complex;

typedef struct s_fractol
{
	void	*conect;
	char	*new_win;
	int		bpp;
	int		ll;
	int		end;
	void	*img;
	char	*pxl;
	int		iter;
	double	shift_x;
	double	shift_y;
	float	min_x;
	float	max_x;
	float	min_y;
	float	max_y;
	double	julia_x;
	double	julia_y;
	char	*name;
	int		c1;
	int		c2;
	int		c3;
}	t_fractol;

double		atod(char *s);
void		init_mlx_hook(t_fractol *frac);
int			key_handler(int keysym, t_fractol *frac);
void		fractal_render(t_fractol *frac);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
void		fractal_render(t_fractol *frac);
void		mlx_error(t_fractol *frac);
void		ft_putstr_fd(char *s, int fd);
int			ft_isdouble(char *s);
void		arg_error(void);
int			ft_strcmp(const char *s1, const char *s2);

#endif
