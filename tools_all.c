/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:36:05 by moel-gha          #+#    #+#             */
/*   Updated: 2024/03/27 12:36:08 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_close(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->window);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	write(1, "closed\n", 8);
	exit(0);
	return (0);
}

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
