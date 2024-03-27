/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 00:02:43 by moel-gha          #+#    #+#             */
/*   Updated: 2024/03/24 00:02:46 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <X11/keysym.h>
# include <ctype.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 800

typedef struct s_data
{
	void			*img;
	void			*addr;
	void			*mlx;
	void			*window;
	int				bpp;
	int				line_length;
	int				offset;
	int				endian;
	double			min;
	double			max;
	int				iteration;
	unsigned int	red;
	unsigned int	blue;
	unsigned int	green;
	char			**fractal;
	double			x;
	double			y;
	double			zoom;
	unsigned int	r_value;
	unsigned int	b_value;
	unsigned int	g_value;
}					t_data;

typedef struct complex
{
	double			i;
	double			r;
}					t_complex;

int					ft_isdigit(int digit);
size_t				ft_strlen(const char *theString);
int					ft_atoi(const char *str);
double				scale(double n, double min, double max, double old_max);
void				put_pixel(t_data *data, int x, int y, unsigned int color);
unsigned int		argb(unsigned int a, unsigned int r, unsigned int g,
						unsigned int b);
int					ft_close(t_data *data);
void				mandelbrot(t_data *data);
int					equa_mandlebort(int x, int y, t_data *data);
void				ft_error(void);
double				ft_atod(const char *str);
void				mng_window(t_data *mlx);
void				deful(t_data *mlx, char **str);
void				ft_generetor(char **str, t_data *mlx);
void				destroyer(t_data *mlx);
int					pars_params(int ac, char **arg);
void				julia(double real, double imgn, t_data *data);
void				colors(t_data *mlx);
int					keyboard_bn(int key, t_data *data);
int					zoom_bn(int cur, int x, int y, t_data *data);
int					move_bn(int key, t_data *data);
void				mng_window_bn(t_data *mlx);
void				ft_generetor_bn(char **str, t_data *mlx);
void				ft_initial(t_data *data);
void				burning(t_data *data);

#endif
