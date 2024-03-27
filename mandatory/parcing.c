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

#include "../fractol.h"

void	ft_error(void)
{
	write(1, "!invalid inputs!\n", 18);
	write(1, "Format :./fractol <number the fractol>\n", 40);
	write(1, "numbers: \nnumber(1) -->mandelbrot\nnumber(2) -->julia\n", 54);
	write(1, "for julia specify the number <real> and <imaginary>\n", 53);
	exit(1);
}

int	valid_num(char *str)
{
	int (i), (flag);
	i = 0;
	flag = 0;
	if ((str[i] == '.') || ((str[i] == '+' || str[i] == '-') \
						&& str[i + 1] == '.'))
		return (0);
	while (str[i])
	{
		if (!(ft_isdigit(str[i]) || (str[0] == '+' || str[0] == '-')))
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
	if (str[i - 1] == '.' || str[i - 1] == '+' || str[i - 1] == '-' )
		return (0);
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
