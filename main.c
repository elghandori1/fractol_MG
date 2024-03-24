/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 00:03:03 by moel-gha          #+#    #+#             */
/*   Updated: 2024/03/24 00:03:05 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	deful(t_data *mlx, char **str)
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
	exit(0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if ((ac < 2 || ac > 4) || pars_params(ac, av))
		ft_error();
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
			&data.indean);
	if (!data.addr)
		destroyer(&data);
	deful(&data, av);
	mng_window(&data);
	if (av[1][0] == '1')
		ft_generetor(av, &data);
	else if (av[1][0] == '2')
		ft_generetor(av, &data);
	mlx_loop(data.mlx);
	return (0);
}
