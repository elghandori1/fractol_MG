/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:10:34 by moel-gha          #+#    #+#             */
/*   Updated: 2024/03/25 11:10:38 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

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

int	keyboard(int key, t_data *data)
{
	if (key == XK_Escape)
		ft_close(data);
	else if (key == 65451)
	{
		data->iteration += 5;
		ft_putnbr(data->iteration);
		write(1, " iterations \n", 13);
		ft_generetor_bn(data);
	}
	else if (key == 65453)
	{
		data->iteration -= 5;
		ft_putnbr(data->iteration);
		write(1, " iterations \n", 13);
		ft_generetor_bn(data);
	}
	else
		k_color(key, data);
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
		ft_generetor_bn(data);
	}
	if (cur == 5)
	{
		data->zoom *= 1.1;
		data->x -= (cursor_x - 0.5) * data->zoom;
		data->y -= (cursor_y - 0.5) * data->zoom;
		ft_generetor_bn(data);
	}
	return (0);
}

int	move(int key, t_data *data)
{
	if (key == 65363)
	{
		data->x += 0.2 * data->zoom;
		ft_generetor_bn(data);
	}
	else if (key == 65362)
	{
		data->y -= 0.2 * data->zoom;
		ft_generetor_bn(data);
	}
	else if (key == 65361)
	{
		data->x -= 0.2 * data->zoom;
		ft_generetor_bn(data);
	}
	else if (key == 65364)
	{
		data->y += 0.2 * data->zoom;
		ft_generetor_bn(data);
	}
	return (0);
}

void	mng_window(t_data *mlx)
{
	mlx_hook(mlx->window, 17, 0, &ft_close, mlx);
	mlx_hook(mlx->window, 2, (1L << 0), &keyboard, mlx);
	mlx_hook(mlx->window, 3, (1L << 1), &move, mlx);
	mlx_mouse_hook(mlx->window, &zoom, mlx);
}
