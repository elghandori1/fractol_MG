/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:09:59 by moel-gha          #+#    #+#             */
/*   Updated: 2024/03/25 11:10:03 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	equa_burning(int x, int y, t_data *m)
{
	int			it;
	t_complex	tmp;
	t_complex	z;
	t_complex	c;

	c.i = scale((double)y, m->min, m->max, HEIGHT) * m->zoom + m->y;
	c.r = scale((double)x, m->min, m->max, WIDTH) * m->zoom + m->x;
	z.i = 0;
	z.r = 0;
	it = 0;
	colors(m);
	while (it++ <= m->iteration)
	{
		tmp.r = (z.r);
		z.r = (fabs(z.r) * fabs(z.r) - fabs(z.i) * fabs(z.i)) + c.r;
		z.i = (2 * fabs(tmp.r * z.i)) + c.i;
		if (fabs((z.r) * (z.r)) + fabs((z.i) * (z.i)) >= 4)
			return (put_pixel(m, x, y, argb(0, m->red, m->green, m->blue)), 0);
		m->red += 10;
		m->blue += 10;
		m->green += 10;
	}
	return (put_pixel(m, x, y, 0x0ffffff), 1);
}

void	burning(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			equa_burning(x, y, data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->window, data->img, 0, 0);
}
