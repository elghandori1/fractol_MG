/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 00:03:30 by moel-gha          #+#    #+#             */
/*   Updated: 2024/03/24 00:03:36 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	int			sign;
	long long	number;
	size_t		i;

	sign = 1;
	number = 0;
	i = 0;
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
	n = 0;
	n1 = (double)ft_atoi(str);
	while (str[i] != '.')
		i++;
	if (str[i] == '.')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		n += (double)(str[i] - 48) / it;
		i++;
		it *= 10;
	}
	if (str[0] == '-')
		n *= -1;
	return (n + n1);
}
