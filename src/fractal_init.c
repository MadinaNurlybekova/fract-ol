#include "../includes/ft_fractol.h"

void    fractal_init(t_fractal *fractal)
{
    fractal->n = 150;
    fractal->max_iterations = 42;
    fractal->x_coord = -2;
    fractal->y_coord = -2;
    fractal->julia_x = -0.70176;
    fractal->julia_y = -0.3842;
    fractal->zoom = 1;
    fractal->offset_y = 0;
    fractal->offset_x = 0;
}