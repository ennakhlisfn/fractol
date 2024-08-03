/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_handling_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sennakhl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:29:21 by sennakhl          #+#    #+#             */
/*   Updated: 2024/05/25 15:54:13 by sennakhl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

double	decimal_point(char *s)
{
	double	res;
	int		dec;
	int		i;

	i = 0;
	dec = 10;
	res = 0.0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		res += ((double)(s[i] - 48)) / dec;
		dec *= 10;
		i++;
	}
	return (res);
}

double	atod(char *s)
{
	int		i;
	int		n;
	double	val;

	n = 1;
	i = 0;
	val = 0.0;
	while (s[i] == ' ')
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			n = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		val = val * 10 + (s[i] - '0');
		i++;
	}
	if (s[i++] == '.')
		val += decimal_point(s + i);
	return (n * val);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!(*s) || fd < 0)
		return ;
	write(fd, s, 1);
	ft_putstr_fd(s + 1, fd);
}

int	ft_isdouble(char *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ')
		i++;
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (s[i] < '0' || s[i] > '9')
		return (0);
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	if (s[i] == 0)
		return (1);
	if (s[i] == '.')
		i++;
	if (s[i] == 0 && (s[i] < '0' || s[i] > '9'))
		return (0);
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	while (s[i] == ' ')
		i++;
	if (s[i])
		return (0);
	return (1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}
