/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 13:35:55 by mnurlybe          #+#    #+#             */
/*   Updated: 2023/07/10 21:02:39 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# include "MLX42.h"
# include "ft_printf.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_fractal
{
	mlx_image_t		*img;
	mlx_t			*mlx;
	double			n;
	long long		y_maxterations;
	double			a_real;
	double			b_img;
	double			julia_x;
	double			julia_y;
	double			x_min;
	double			x_max;
	double			y_min;
	double			y_max;
	double			color_shift;
	char			set;
	double			z;
}					t_fractal;

typedef struct s_color
{
	int				r;
	int				g;
	int				b;
	int				tp;
}					t_color;

union				u_color
{
	unsigned int	number;
	unsigned char	channels[4];
};

void				fractal_init(t_fractal *fractal);
int32_t				ft_fractal(char *set);

int					calculate_mandelbox_set(t_fractal *f);
int					calculate_mandelbrot_set(t_fractal *f);
int					calculate_julia_set(t_fractal *f);
void				draw_fractal(void *p);

// colors
int					rgb(int i);
void				color_shift(void *p);
void				ft_colorize(t_fractal *f, int x, int y, int i);

// hooks
void				my_key_hook(void *ptr);
void				scrollfunc(double xdelta, double ydelta, void *param);

// errors
void				ft_print_error(void);

void				move_julia(void *ptr);

#endif
