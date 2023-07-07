#include "../includes/ft_fractol.h"

// ================================ JULIA ===========================
void draw_julia(void *p)
{
    t_fractal *fractal;
    fractal = p;

    fractal->y_coord = 0;
    fractal->x_coord = 0; 
    double x;
    double y;
    double temp;
    int i;
    
    while (fractal->y_coord < 4 * fractal->n)
    {
        y = 2 - (fractal->y_coord / fractal->n);
        while (fractal->x_coord < 4 * fractal->n)
        {
            x = - 2 + (fractal->x_coord / fractal->n);
            fractal->a_real = x/fractal->zoom - fractal->offset_x;
            fractal->b_img = y/fractal->zoom - fractal->offset_y;
            i = 1;
            while(i <= fractal->max_iterations)
            {
                temp = fractal->a_real;
                fractal->a_real = (fractal->a_real * fractal->a_real) - (fractal->b_img * fractal->b_img) + fractal->julia_x;
                fractal->b_img = (2 * temp * fractal->b_img) + fractal->julia_y;
                if ((fractal->a_real * fractal->a_real) + (fractal->b_img * fractal->b_img) > 4)
                    break; 
                i++;
            }
            if (i == fractal->max_iterations + 1)
                mlx_put_pixel(fractal->img, fractal->x_coord, fractal->y_coord, 0x000000FF); //black
            else
                // mlx_put_pixel(fractal->img, fractal->x_coord, fractal->y_coord,  0xFFFFFFFF); //white
                mlx_put_pixel(fractal->img, fractal->x_coord, fractal->y_coord,  foo(i + 250)); //colored
            fractal->x_coord++;
        }
        fractal->x_coord = 0;
        fractal->y_coord++;
    }
    mlx_image_to_window(fractal->mlx, fractal->img, 0, 0);
}


// ================================ MANDELBROT ===========================
void draw_mandelbrot(void *p)
{
    t_fractal *fractal;
    fractal = p;
    fractal->y_coord = 0;
    fractal->x_coord = 0; 
    double x;
    double y;
    double temp;
    int i;
    
    while (fractal->y_coord < 4 * fractal->n)
    {
        y = 2 - (fractal->y_coord / fractal->n);
        while (fractal->x_coord < 4 * fractal->n)
        {
            x = - 2 + (fractal->x_coord / fractal->n);
            fractal->a_real = x/fractal->zoom - fractal->offset_x;
            fractal->b_img = y/fractal->zoom - fractal->offset_y;
            i = 1;
            while(i <= fractal->max_iterations)
            {
                temp = fractal->a_real;
                fractal->a_real = (fractal->a_real * fractal->a_real) - (fractal->b_img * fractal->b_img) + x;
                fractal->b_img = (2 * temp * fractal->b_img) + y;
                if ((fractal->a_real * fractal->a_real) + (fractal->b_img * fractal->b_img) > 16)
                    break; 
                i++;
            }
            if (i == fractal->max_iterations + 1)
                mlx_put_pixel(fractal->img, fractal->x_coord , fractal->y_coord, 0xFFFFFFFF); //black
            else
                mlx_put_pixel(fractal->img, fractal->x_coord, fractal->y_coord,  foo(i + 250)); //colored
            fractal->x_coord++;
        }
        fractal->x_coord = 0;
        fractal->y_coord++;
    }
    mlx_image_to_window(fractal->mlx, fractal->img, 0, 0);
}

void ft_print_error(int error)
{
    if (error == 1)
    {
        write(1, "Incorrent amount of arguments\n", 30);
    }
    if (error == 2)
    {
        write(1, "Wrong input\n", 12);
    }
}

int32_t    ft_fractal(char set)
{
    t_fractal *fractal;
    fractal = malloc(sizeof(t_fractal));
    fractal_init(fractal);
	// mlx_set_setting(MLX_MAXIMIZED, true);
	fractal->mlx = mlx_init(fractal->n * 4, fractal->n * 4, "Fract", true);
	if (!fractal->mlx)
		ft_error();
	fractal->img = mlx_new_image(fractal->mlx, fractal->n * 4, fractal->n * 4);
	if (!fractal->img || (mlx_image_to_window(fractal->mlx, fractal->img, 0, 0) < 0))
		ft_error();

    mlx_scroll_hook(fractal->mlx, my_scrollhook, fractal);
    if (set == 'J')
        mlx_loop_hook(fractal->mlx, draw_julia, fractal);
    else if (set == 'M')
        mlx_loop_hook(fractal->mlx, draw_mandelbrot, fractal);
        
    mlx_loop_hook(fractal->mlx, hook, fractal);
	mlx_loop(fractal->mlx);
	// mlx_delete_image(fractal->mlx, fractal->img);
	mlx_terminate(fractal->mlx);
    return (EXIT_SUCCESS);
}

int32_t	main(int argc, char **argv)
{
    char set;

    if (argc != 2)
    {
        ft_print_error(1);
        return (0);
    }
    set = argv[1][0];
    if ((set == 'J' && argv[1][1] == '\0') || (set == 'M' && argv[1][1] == '\0'))
        return(ft_fractal(set));
    else 
    {
        ft_print_error(2);
        return (0);
    }
}