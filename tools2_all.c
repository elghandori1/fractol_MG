/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:36:38 by moel-gha          #+#    #+#             */
/*   Updated: 2024/03/27 12:36:40 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_isdigit(int digit)
{
	if (digit >= 48 && digit <= 57)
		return (1);
	return (0);
}

size_t	ft_strlen(const char *theString)
{
	int	i;

	i = 0;
	while (theString[i])
	{
		i++;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	long long	number;
	size_t		i;
	int			sign;

	sign = 1;
	number = 0;
	i = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + (str[i] - '0');
		i++;
	}
	return (number * sign);
}

double	ft_atod(const char *str)
{
	double	n;
	size_t	i;
	double	n1;
	double	it;

	it = 10.0;
	i = 0;
	n = 0.0;
	n1 = (double)ft_atoi(str);
	while (str[i] != '.' && str[i] != '\0')
		i++;
	if (str[i] == '.')
	{
		i++;
		while (str[i] >= '0' && str[i] <= '9' && str[i])
		{
			n += (double)(str[i] - 48) / it;
			i++;
			it *= 10;
		}
	}
	if (str[0] == '-')
		n *= -1;
	return (n + n1);
}
