#include "../includes/ft_fractol.h"

void    fractal_init(t_fractal *fractal)
{
    fractal->n = 100;
    fractal->max_iterations = 100;
    fractal->julia_x = 0.285;
    fractal->julia_y = 0.01;

    fractal->min_i = -2.0;
	fractal->min_r = -2.0;
	fractal->max_r = 2.0;
    fractal->max_i = 2.0;
}
