/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <moel-gha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 00:03:13 by moel-gha          #+#    #+#             */
/*   Updated: 2024/03/24 00:12:14 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	equa_mandlebort(int x, int y, t_data *data)
{
	int			it;
	t_complex	tmp;
	t_complex	z;
	t_complex	c;

	c.i = scale((double)y, data->min, data->max, HEIGHT) * data->zoom + data->y;
	c.r = scale((double)x, data->min, data->max, WIDTH) * data->zoom + data->x;
	z.i = 0.0;
	z.r = 0.0;
	it = 0;
	colors(data);
	while (it++ <= data->iteration)
	{
		tmp.r = (z.r);
		z.r = ((z.r) * (z.r) - (z.i) * (z.i)) + c.r;
		z.i = (2 * tmp.r * z.i) + c.i;
		if (((z.r) * (z.r) + (z.i) * (z.i)) >= 4)
			return (put_pixel(data, x, y, argb(0, data->red, data->green,
						data->blue)), 0);
		data->red += 10;
		data->blue += 10;
		data->green += 10;
	}
	return (put_pixel(data, x, y, 0x0ffffff), 1);
}

void	mandelbrot(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			equa_mandlebort(x, y, data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->window, data->img, 0, 0);
}
