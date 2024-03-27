/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:39:05 by moel-gha          #+#    #+#             */
/*   Updated: 2024/03/27 12:39:13 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	equa_julia(t_complex c_j, int x, int y, t_data *data)
{
	int				it;
	t_complex		tmp;
	t_complex		z;
	t_complex		c;

	z.i = scale((double)y, data->min, data->max, HEIGHT) * data->zoom + data->y;
	z.r = scale((double)x, data->min, data->max, WIDTH) * data->zoom + data->x;
	c.i = c_j.i;
	c.r = c_j.r;
	it = 0;
	colors(data);
	while (it++ <= data->iteration)
	{
		tmp.r = z.r;
		z.r = ((z.r) * (z.r) - (z.i) * (z.i)) + c.r;
		z.i = (2 * tmp.r * z.i) + c.i;
		if ((z.r) * (z.r) + (z.i) * (z.i) >= 4)
			return (put_pixel(data, x, y,
					argb(0, data->red, data->green, data->blue)), 0);
		data->red += 10;
		data->blue += 10;
		data->green += 10;
	}
	return (put_pixel(data, x, y, 0x0ffffff), 1);
}

void	julia(double real, double imgn, t_data *data)
{
	int			y;
	int			x;
	t_complex	c;

	y = 0;
	c.i = imgn;
	c.r = real;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			equa_julia(c, x, y, data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->window, data->img, 0, 0);
}
