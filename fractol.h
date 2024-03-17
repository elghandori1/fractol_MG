#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
#include <string.h>
 #include <ctype.h>

typedef struct s_data
{

	void			*mlx;
	void			*window;
}	t_data;

int pars_params(int num,char **arg);
void	ft_error(void);

#endif