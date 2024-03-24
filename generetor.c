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

void	colors(t_data *mlx)
{
	mlx->red = 0 + mlx->r_value;
	mlx->blue = 0 + mlx->b_value;
	mlx->green = 0 + mlx->g_value;
}

void	ft_generetor(char **str, t_data *mlx)
{
	if (str[1][0] == '1')
		mandelbrot(mlx);
	else if (str[1][0] == '2')
		julia(ft_atod(str[2]), ft_atod(str[3]), mlx);
}
