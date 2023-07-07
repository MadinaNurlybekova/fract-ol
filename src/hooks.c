#include "../includes/ft_fractol.h"

// key hook
void hook(void *ptr)
{
    t_fractal *fr;
    fr = ptr;

    if (mlx_is_key_down(fr->mlx, MLX_KEY_LEFT)){
        fr->offset_x -= 0.4;
        printf("%f", fr->offset_x );
		puts("MLX_KEY_LEFT ");
    }
    if (mlx_is_key_down(fr->mlx, MLX_KEY_RIGHT)){
        fr->offset_x += 0.4;
        
        puts("MLX_KEY_RIGHT ");
    }
    if (mlx_is_key_down(fr->mlx, MLX_KEY_UP)){
        fr->offset_y += 0.4;
        puts("MLX_KEY_UP ");
    }
    if (mlx_is_key_down(fr->mlx, MLX_KEY_DOWN)){
        fr->offset_y -= 0.4;
        puts("MLX_KEY_DOWN ");
    }

}

// void my_scrollhook(double xdelta, double ydelta, void* param)
// {
//     t_fractal *fractal;
//     (void)xdelta;

//     fractal = param;
//     int x, y;
//     mlx_get_mouse_pos(fractal->mlx, &(x), &(y));
//     fractal->offset_x =  x/1000.;
//     fractal->offset_y=  y/1000.;
// 	if (ydelta > 0)
// 		fractal->zoom ++;
// 	else if (ydelta < 0)
// 		fractal->zoom --;
//     fractal->y_coord = 0;
//     fractal->x_coord = 0; 
// }

// void my_scrollhook(double xdelta, double ydelta, void* param)
// {
//     t_fractal *fractal;
// 	long double	len;
//     long double	l = 0.0078125;
//     int x, y;

// 	fractal = param;
// 	len = l;
//     (void)xdelta;
//     // long double w = fractal->n * 4;
//     // long double h = fractal->n * 4;

// 	mlx_get_mouse_pos(fractal->mlx, &(x), &(y));
// 	if (ydelta < 0 && fractal->zoom > 1 && x >= 0
// 		&& x <= fractal->n * 4 - 1 && y >= 0 && y <= fractal->n * 4 - 1)
// 	{
// 		fractal->zoom --;
// 		l *= 1.25;
// 	}
// 	if (ydelta > 0 && fractal->zoom < (fractal->n * 4)/2 && x >= 0
// 		&& x <= fractal->n * 4 && y>= 0 && y<= fractal->n * 4)
// 	{
// 		fractal->zoom ++;
// 		l *= 0.8;
// 	}
// 	if (xdelta < 0)
// 		fractal->zoom += 0;
// 	fractal->x_coord += x * len - x * l;
// 	fractal->y_coord += y * len - y * l;
//     // fractal->x_coord = 0;
//     // fractal->y_coord = 0;

//     // fractal->x_coord += x - x * (w / fractal->zoom + fractal->zoom * 0.05);
//     // fractal->y_coord += y - y * (h / fractal->zoom + fractal->zoom * 0.05);
//     // w = w - (w / fractal->zoom + fractal->zoom * 0.05);
//     // h = h - (h / fractal->zoom + fractal->zoom * 0.05);

//     // fractal->x_coord += x - x * (w / 105);
//     // fractal->y_coord += y - y * (h / 105);
//     // w = w - (w / 105);
//     // h = h - (h / 105);
// }

void my_scrollhook(double xdelta, double ydelta, void* param)
{
	double	zoom_level;
    t_fractal *fractal;
    int x, y;

	fractal = param;
    (void)xdelta;

	zoom_level = 1.42;
    mlx_get_mouse_pos(fractal->mlx, &(x), &(y));
	if (ydelta > 0 && fractal->zoom < (fractal->n * 4)/2 && x >= 0
		&& x <= fractal->n * 4 && y>= 0 && y<= fractal->n * 4)
    {
		fractal->offset_x = (x / fractal->zoom + fractal->offset_x) - (x
				/ (fractal->zoom * zoom_level));
		fractal->offset_y = (y / fractal->zoom + fractal->offset_y) - (y
				/ (fractal->zoom * zoom_level));
		fractal->zoom *= zoom_level;
	}
	if (ydelta < 0 && fractal->zoom > 1 && x >= 0
		&& x <= fractal->n * 4 - 1 && y >= 0 && y <= fractal->n * 4 - 1)
	{
		fractal->offset_x = (x / fractal->zoom + fractal->offset_x) - (x
				/ (fractal->zoom / zoom_level));
		fractal->offset_y = (y / fractal->zoom + fractal->offset_y) - (y
				/ (fractal->zoom / zoom_level));
		fractal->zoom /= zoom_level;
	}
    fractal->offset_x /= 1000.;
    fractal->offset_y /= 1000.;
}

// void mouse_hook(void *ptr)
// {
//     t_fractal *fractal;
//     fractal = ptr;

//     int x, y;

//     mlx_get_mouse_pos(fractal->mlx, &(x), &(y));
//     if (mlx_is_mouse_down(fractal->mlx, MLX_MOUSE_BUTTON_MIDDLE))
//     {
//         printf("in");
// 		zoom(fractal, x, y, 1);
//     }
// 	// if (mlx_is_mouse_down(fractal->mlx, MLX_MOUSE_BUTTON_MIDDLE))
//     // {
//     //     printf("out");
// 	// 	zoom(fractal, x, y, -1);
//     // }
// }


// mOffset = event->pos() - float(mZoomLevel) / float(oldZoomLevel) * (event->pos() - mOffset);