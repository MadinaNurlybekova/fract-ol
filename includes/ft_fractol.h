/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 13:35:55 by mnurlybe          #+#    #+#             */
/*   Updated: 2023/07/08 16:48:43 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_fractal
{ 
    mlx_image_t *img;
    int img_w;
    long long max_iterations;
    int img_h;
    mlx_t *mlx;
    int x_coord;
    int y_coord;
    double a_real;
    double b_img;
    double n;
    double julia_x;
    double julia_y;
    double zoom;
    double old_zoom;
    double offset_x;
    double offset_y;
    double previous_offset_x;
    double previous_offset_y;
    
	  double	min_r;
	  double	max_r;
	  double	min_i;
	  double	max_i;
    
} t_fractal;

typedef struct s_color
{
    int r;
    int g;
    int b;
    int tp;
}   t_color;

union       colour_u
{
  unsigned int  number;
  unsigned char channels[4];
};

void draw_julia(void *p);
void draw_mandelbrot(void *p);
void    fractal_init(t_fractal *fractal);
void    ft_error(void);
void ft_print_error(int error);
int32_t    ft_fractal(char set);

// colors
int foo(int continuous_index);

// hooks
void hook(void *ptr); //key
void scrollfunc(double xdelta, double ydelta, void* param);
// void my_scrollhook(double xdelta, double ydelta, void* param); //zoom
// void mouse_hook(void *ptr);
// void	zoom(t_fractal *fractal, int x, int y, int zoom);


void draw_julia_2(void *p);


#endif

//  gcc src/main.c libmlx42.a -Iinclude -ldl -lglfw -pthread -lm 