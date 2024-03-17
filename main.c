#include "fractol.h"

int main(int ac, char **av) 
{   
    if(ac < 2 || ac >4)
         ft_error();
    if (pars_params(ac, av))
        ft_error();
    printf("ok\n");
    return 0;
}