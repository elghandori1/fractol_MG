/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 00:03:23 by moel-gha          #+#    #+#             */
/*   Updated: 2024/03/24 00:03:25 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error(void)
{
	write(1, "!invalid inputs!\n", 18);
	write(1, "Format :./fractol <number the fractol>\n", 40);
	write(1, "numbers: \nnumber(1) -->mandelbrot\nnumber(2) -->julia\n", 54);
	write(1, "for julia specify the number <real> and <imaginary>\n", 53);
	exit(1);
}

int	k_color(int key, t_data *mlx)
{
	if (key == XK_a)
		return (mlx->r_value += 15, ft_generetor(mlx->fractal, mlx), 0);
	else if (key == XK_s)
		return (mlx->g_value += 15, ft_generetor(mlx->fractal, mlx), 0);
	else if (key == XK_d)
		return (mlx->b_value += 15, ft_generetor(mlx->fractal, mlx), 0);
	if (key == XK_q)
		return (mlx->r_value -= 15, ft_generetor(mlx->fractal, mlx), 0);
	else if (key == XK_w)
		return (mlx->g_value -= 15, ft_generetor(mlx->fractal, mlx), 0);
	else if (key == XK_e)
		return (mlx->b_value -= 15, ft_generetor(mlx->fractal, mlx), 0);
	return (0);
}

int	valid_num(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (str[i])
	{
		if (!(ft_isdigit(str[i]) || (i == 0 && (str[i] == '+'
						|| str[i] == '-'))))
		{
			if (str[i] == '.')
			{
				if (flag)
					return (0);
				else
					flag = 1;
			}
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	pars_params(int ac, char **arg)
{
	int	lenght;

	lenght = ft_strlen(arg[1]);
	if (lenght != 1 || (arg[1][0] < '1' || arg[1][0] > '2'))
		return (1);
	else if (arg[1][0] == '2')
	{
		if (ac != 4)
			return (1);
		else if (!(valid_num(arg[2])) || !(valid_num(arg[3])))
			return (1);
	}
	else if (ac > 2)
		return (1);
	return (0);
}
