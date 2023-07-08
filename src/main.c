#include "../includes/ft_fractol.h"

// ================================ JULIA ===========================
// void draw_julia(void *p)
// {
//     t_fractal *fractal;
//     fractal = p;

//     fractal->y_coord = 0;
//     fractal->x_coord = 0; 
//     double x;
//     double y;
//     double temp;
//     int i;
    
//     while (fractal->y_coord < 4 * fractal->n)
//     {
//         y = 2 - (fractal->y_coord / fractal->n);
//         while (fractal->x_coord < 4 * fractal->n)
//         {
//             x = - 2 + (fractal->x_coord / fractal->n);
//             fractal->a_real = x/fractal->zoom - fractal->offset_x;
//             fractal->b_img = y/fractal->zoom - fractal->offset_y;
//             i = 1;
//             while(i <= fractal->max_iterations)
//             {
//                 temp = fractal->a_real;
//                 fractal->a_real = (fractal->a_real * fractal->a_real) - (fractal->b_img * fractal->b_img) + fractal->julia_x;
//                 fractal->b_img = (2 * temp * fractal->b_img) + fractal->julia_y;
//                 if ((fractal->a_real * fractal->a_real) + (fractal->b_img * fractal->b_img) > 4)
//                     break; 
//                 i++;
//             }
//             if (i == fractal->max_iterations + 1)
//                 mlx_put_pixel(fractal->img, fractal->x_coord, fractal->y_coord, foo(i + 050)); //black
//             else
//                 // mlx_put_pixel(fractal->img, fractal->x_coord, fractal->y_coord,  0xFFFFFFFF); //white
//                 mlx_put_pixel(fractal->img, fractal->x_coord, fractal->y_coord,  foo(i + 500)); //colored
//             fractal->x_coord++;
//         }
//         fractal->x_coord = 0;
//         fractal->y_coord++;
//     }
//     mlx_image_to_window(fractal->mlx, fractal->img, 0, 0);
// }

void draw_julia_2(void *p)
{
    t_fractal *f;
    f = p;

    int x, y;
    int i;
    double	tmp;

    y = 0;
    while (y < 4 * f->n)
    {
        x = 0;
        while (x < 4 * f->n)
        {
			f->a_real = f->min_r + (double)x * (f->max_r - f->min_r) / (f->n * 4);
			f->b_img = f->max_i + (double)y * (f->min_i - f->max_i) / (f->n * 4);

            i = 1;
            while (i <= f->max_iterations)
            {
                if ((f->b_img * f->b_img + f->a_real * f->a_real) > 4.0)
                    break ;
                tmp = 2 * f->a_real * f->b_img + f->julia_y;
                f->a_real = f->a_real * f->a_real - f->b_img * f->b_img + f->julia_x;
                f->b_img = tmp;
                i++;
            }
            if (i == f->max_iterations + 1)
                mlx_put_pixel(f->img, x, y, foo(i + 999)); //black
            else
                mlx_put_pixel(f->img, x, y,  foo(i + 746)); //colored
            x++;
        }
        y++;
    }
    mlx_image_to_window(f->mlx, f->img, 0, 0);
}



// ================================ MANDELBROT ===========================

void draw_mandelbrot(void *p)
{
    t_fractal *f;
    f = p;

    int x, y;
    int i;
    double	tmp;
    double mr, mi;

    y = 0;
    while (y < 4 * f->n)
    {
        x = 0;
        while (x < 4 * f->n)
        {
			mr = f->min_r + (double)x * (f->max_r - f->min_r) / (f->n * 4);
			mi = f->max_i + (double)y * (f->min_i - f->max_i) / (f->n * 4);
            f->a_real = 0;
            f->b_img = 0;
            i = 1;
            while (i <= f->max_iterations)
            {
                if ((f->b_img * f->b_img + f->a_real * f->a_real) > 4.0)
                    break ;
                tmp = 2 * f->a_real * f->b_img + mi;
                f->a_real = f->a_real * f->a_real - f->b_img * f->b_img + mr;
                f->b_img = tmp;
                i++;
            }
            if (i == f->max_iterations + 1)
                mlx_put_pixel(f->img, x, y, foo(i + 999)); //black
            else
                mlx_put_pixel(f->img, x, y,  foo(i + 746)); //colored
            x++;
        }
        y++;
    }
    mlx_image_to_window(f->mlx, f->img, 0, 0);
}

// =========================== MANDELBOX ==========================

// v = s*ballFold(r, f*boxFold(v)) + c

double boxFold(double v)
{
    if (v > 1.0)
        v = 2.0 - v;
    else if (v < -1.0)
        v = - 2.0 - v;
    return (v);
}

double magnitude(double m, double v)
{
    double scale = -1.1;
    if (m < 0.5)
        v *= 4;
    else if (m < 1.0)
        v = v / (m * m);
    else
        v = scale * v;
    return (v);
}

void draw_mandelbox(void *p)
{
    t_fractal *f;
    f = p;
    int x, y;
    int i;
    double mr, mi;
    double vx, vy;
    double scale = 2;
    double mag;

    y = 0;
    while (y < 4 * f->n)
    {
        x = 0;
        while (x < 4 * f->n)
        {
			mr = f->min_r + (double)x * (f->max_r - f->min_r) / (f->n * 4);
			mi = f->max_i + (double)y * (f->min_i - f->max_i) / (f->n * 4);
            vx = mr;
            vy = mi;
            i = 1;
            while (i <= f->max_iterations)
            {
                vx = boxFold(vx);
                vy = boxFold(vy);
                mag = sqrt(vx*vx + vy*vy);
                if (vx*vx + vy*vy > 4.0)
                    break;
                vx = scale * magnitude(mag, vx) + mr;
                vy = scale * magnitude(mag, vy) + mi;
                i++;
            }
            if (i == f->max_iterations + 1)
                mlx_put_pixel(f->img, x, y, foo(i + 999)); //black
            else
                mlx_put_pixel(f->img, x, y,  foo(i + 746)); //colored
            x++;
        }
        y++;
    }
    mlx_image_to_window(f->mlx, f->img, 0, 0);
}



// void draw_mandelbrot(void *p)
// {
//     t_fractal *f;
//     f = p;
//     double x = 0;
//     double y = 0;
//     double temp;
//     int i;
//     double zr, zi;
    
//     while (y < 4 * f->n)
//     {
//         while (x < 4 * f->n)
//         {
// 			zr = f->min_r + (double)x * (f->max_r - f->min_r) / (f->n * 4);
// 			zi = f->max_i + (double)y * (f->min_i - f->max_i) / (f->n * 4);
//             i = 1;
//             f->a_real = 0;
//             f->b_img = 0;
//             while(i <= f->max_iterations)
//             {
//                 temp = f->a_real;
//                 f->a_real = (f->a_real * f->a_real) - (f->b_img * f->b_img) + zr;
//                 f->b_img = (2 * temp * f->b_img) + zi;
//                 if ((f->a_real * f->a_real) + (f->b_img * f->b_img) > 16)
//                     break; 
//                 i++;
//             }
//             if (i == f->max_iterations + 1)
//                 mlx_put_pixel(f->img, x , y, 0xFFFFFFFF); //black
//             else
//                 mlx_put_pixel(f->img, x, y,  foo(i + 250)); //colored
//             x++;
//         }
//         x = 0;
//         y++;
//     }
//     mlx_image_to_window(f->mlx, f->img, 0, 0);
// }

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

    mlx_loop_hook(fractal->mlx, hook, fractal);

    if (set == 'J')
        mlx_loop_hook(fractal->mlx, draw_julia_2, fractal);
    else if (set == 'M')
        mlx_loop_hook(fractal->mlx, draw_mandelbox, fractal);
        
    mlx_scroll_hook(fractal->mlx, scrollfunc, fractal);
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