/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generetor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <moel-gha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 00:02:54 by moel-gha          #+#    #+#             */
/*   Updated: 2024/03/24 00:12:54 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	scale(double n, double min, double max, double maximum)
{
	return ((max - min) * (n - 0) / (maximum) + min);
}

unsigned int	argb(unsigned int a, unsigned int r, unsigned int g,
					unsigned int b)
{
	return (a << 24 | r << 16 | g << 8 | b);
}

void	put_pixel(t_data *data, int x, int y, unsigned int color)
{
	char	*ofst;

	ofst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)ofst = color;
}

void	ft_generetor(char **str, t_data *mlx)
{
	if (str[1][0] == '1')
		mandelbrot(mlx);
}

double	ft_atod(const char *str)
{
	double	n;
	size_t	i;
	double	n1;
	double	it;

	it = 10.0;
	i = 0;
	n = 0;
	n1 = (double)ft_atoi(str);
	while (str[i] != '.')
		i++;
	if (str[i] == '.')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		n += (double)(str[i] - 48) / it;
		i++;
		it *= 10;
	}
	if (str[0] == '-')
		n *= -1;
	return (n + n1);
}
