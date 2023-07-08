#include "../includes/ft_fractol.h"

void    fractal_init(t_fractal *fractal)
{
    fractal->n = 100;
    fractal->max_iterations = 2000;
    fractal->x_coord = -2;
    fractal->y_coord = -2;
    fractal->julia_x = 0.285;
    fractal->julia_y = 0.01;
    fractal->zoom = 1;
    fractal->offset_y = 0;
    fractal->offset_x = 0;

    fractal->min_i = -2.0;
	fractal->min_r = -2.0;
	fractal->max_r = 2.0;
    fractal->max_i = fractal->min_i + (fractal->max_r - fractal->min_r) * (fractal->n * 4) / (fractal->n * 4);
}

    // fractal->max_i = fractal->min_i + (fractal->max_r - fractal->min_r) * (fractal->n * 4) / (fractal->n * 4);