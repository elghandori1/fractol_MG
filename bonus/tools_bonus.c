/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:11:27 by moel-gha          #+#    #+#             */
/*   Updated: 2024/03/25 11:11:29 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	ft_putnbr(int n)
{
	char	c;

	if (n < 0)
	{
		c = '-';
		write(1, &c, 1);
		n = -(n);
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		c = n + 48;
		write(1, &c, 1);
	}
}

int	k_color(int key, t_data *mlx)
{
	if (key == XK_a)
		return (mlx->r_value += 15, ft_generetor_bn(mlx), 0);
	else if (key == XK_s)
		return (mlx->g_value += 15, ft_generetor_bn(mlx), 0);
	else if (key == XK_d)
		return (mlx->b_value += 15, ft_generetor_bn(mlx), 0);
	if (key == XK_q)
		return (mlx->r_value -= 15, ft_generetor_bn(mlx), 0);
	else if (key == XK_w)
		return (mlx->g_value -= 15, ft_generetor_bn(mlx), 0);
	else if (key == XK_e)
		return (mlx->b_value -= 15, ft_generetor_bn(mlx), 0);
	return (0);
}
