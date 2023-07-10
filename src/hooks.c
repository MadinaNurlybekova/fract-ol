/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 20:27:03 by mnurlybe          #+#    #+#             */
/*   Updated: 2023/07/10 21:04:46 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

void	my_key_hook(void *ptr)
{
	t_fractal	*f;

	f = ptr;
	if (mlx_is_key_down(f->mlx, MLX_KEY_RIGHT))
	{
		f->x_min -= (f->x_max - f->x_min) * 0.04;
		f->x_max -= (f->x_max - f->x_min) * 0.04;
	}
	if (mlx_is_key_down(f->mlx, MLX_KEY_LEFT))
	{
		f->x_min += (f->x_max - f->x_min) * 0.04;
		f->x_max += (f->x_max - f->x_min) * 0.04;
	}
	if (mlx_is_key_down(f->mlx, MLX_KEY_DOWN))
	{
		f->y_min += (f->y_max - f->y_min) * 0.04;
		f->y_max += (f->y_max - f->y_min) * 0.04;
	}
	if (mlx_is_key_down(f->mlx, MLX_KEY_UP))
	{
		f->y_min -= (f->y_max - f->y_min) * 0.04;
		f->y_max -= (f->y_max - f->y_min) * 0.04;
	}
	if (mlx_is_key_down(f->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(f->mlx);
}

static void	ft_zoom(t_fractal *f, double ydelta)
{
	double	x_middle;
	double	y_middle;

	if (ydelta > 0)
		f->z = 0.5;
	else if (ydelta < 0)
		f->z = 2.0;
	x_middle = f->x_min - f->x_max;
	y_middle = f->y_max - f->y_min;
	f->x_max += (x_middle - f->z * x_middle) / 2;
	f->x_min = f->x_max + f->z * x_middle;
	f->y_min += (y_middle - f->z * y_middle) / 2;
	f->y_max = f->y_min + f->z * y_middle;
}

static void	ft_mouse_move(t_fractal *f, double distance, char arrow)
{
	double	x_middle;
	double	y_middle;

	x_middle = f->x_max - f->x_min;
	y_middle = f->y_max - f->y_min;
	if (arrow == '6')
	{
		f->x_min += x_middle * distance;
		f->x_max += x_middle * distance;
	}
	else if (arrow == '4')
	{
		f->x_min -= x_middle * distance;
		f->x_max -= x_middle * distance;
	}
	else if (arrow == '2')
	{
		f->y_min -= y_middle * distance;
		f->y_max -= y_middle * distance;
	}
	else if (arrow == '8')
	{
		f->y_min += y_middle * distance;
		f->y_max += y_middle * distance;
	}
}

void	scrollfunc(double xdelta, double ydelta, void *param)
{
	t_fractal	*f;
	int			x;
	int			y;

	f = param;
	(void)xdelta;
	mlx_get_mouse_pos(f->mlx, &(x), &(y));
	if (ydelta > 0)
	{
		ft_zoom(f, ydelta);
		x -= (f->n) / 2;
		y -= (f->n) / 2;
		if (x < 0)
			ft_mouse_move(f, (double)x * -1 / f->n, '4');
		else if (x > 0)
			ft_mouse_move(f, (double)x / f->n, '6');
		if (y < 0)
			ft_mouse_move(f, (double)y * -1 / f->n, '8');
		else if (y > 0)
			ft_mouse_move(f, (double)y / f->n, '2');
	}
	else if (ydelta < 0)
		ft_zoom(f, ydelta);
}

void	move_julia(void *ptr)
{
	t_fractal	*fractal;

	fractal = ptr;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_Z))
		fractal->julia_x -= 0.005;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_X))
		fractal->julia_x += 0.005;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_C))
		fractal->julia_y += 0.01;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_V))
		fractal->julia_y -= 0.01;
}
