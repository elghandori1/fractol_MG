/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 00:02:32 by moel-gha          #+#    #+#             */
/*   Updated: 2024/03/24 00:02:36 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	keyboard(int key, t_data *data)
{
	if (key == XK_Escape)
		ft_close(data);
	else if (key == 65451)
	{
		data->iteration += 5;
		ft_generetor(data->fractal, data);
	}
	else if (key == 65453)
	{
		data->iteration -= 5;
		ft_generetor(data->fractal, data);
	}
	return (0);
}

int	zoom(int cur, int x, int y, t_data *data)
{
	double	cursor_x;
	double	cursor_y;

	cursor_x = (double)x / WIDTH;
	cursor_y = (double)y / HEIGHT;
	if (cur == 4)
	{
		data->zoom *= 0.9;
		data->x += (cursor_x - 0.5) * data->zoom;
		data->y += (cursor_y - 0.5) * data->zoom;
		ft_generetor(data->fractal, data);
	}
	if (cur == 5)
	{
		data->zoom *= 1.1;
		data->x -= (cursor_x - 0.5) * data->zoom;
		data->y -= (cursor_y - 0.5) * data->zoom;
		ft_generetor(data->fractal, data);
	}
	return (0);
}

void	mng_window(t_data *mlx)
{
	mlx_hook(mlx->window, 17, 0, &ft_close, mlx);
	mlx_hook(mlx->window, 2, (1L << 0), &keyboard, mlx);
	mlx_mouse_hook(mlx->window, &zoom, mlx);
}
