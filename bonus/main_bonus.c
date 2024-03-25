/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:11:11 by moel-gha          #+#    #+#             */
/*   Updated: 2024/03/25 11:11:13 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	deful_bn(t_data *mlx, char **str)
{
	mlx->red = 0;
	mlx->blue = 0;
	mlx->green = 0;
	mlx->r_value = 0;
	mlx->g_value = 0;
	mlx->b_value = 0;
	mlx->iteration = 30;
	mlx->max = 2;
	mlx->min = -2;
	mlx->fractal = str;
	mlx->x = 0;
	mlx->y = 0;
	mlx->zoom = 1;
}

void	destroyer(t_data *mlx)
{
	perror("an error occured\n");
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx_destroy_display(mlx->mlx);
	mlx_destroy_window(mlx->mlx, mlx->window);
	free(mlx->mlx);
	exit(0);
}

void	ft_generetor_bn(t_data *mlx)
{
	burning(mlx);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac > 1)
	{
		write(1, "takes no args!!\n", 16);
		exit(0);
	}
	data.mlx = mlx_init();
	if (!data.mlx)
		destroyer(&data);
	data.window = mlx_new_window(data.mlx, WIDTH, HEIGHT, "fractal");
	if (!data.window)
		destroyer(&data);
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	if (!data.img)
		destroyer(&data);
	data.addr = mlx_get_data_addr(data.img, &data.bpp, &data.line_length,
			&data.endian);
	if (!data.addr)
		destroyer(&data);
	deful_bn(&data, av);
	mng_window(&data);
	ft_generetor_bn(&data);
	mlx_loop(data.mlx);
	return (0);
}
