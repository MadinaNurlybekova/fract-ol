/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 20:19:12 by mnurlybe          #+#    #+#             */
/*   Updated: 2023/07/10 21:02:30 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

void	draw_fractal(void *p)
{
	t_fractal	*f;
	int			i;
	int			x;
	int			y;

	f = p;
	y = 0;
	while (y++ < f->n)
	{
		x = 0;
		while (x++ < f->n)
		{
			f->a_real = f->x_min + (double)x * (f->x_max - f->x_min) / f->n;
			f->b_img = f->y_max + (double)y * (f->y_min - f->y_max) / f->n;
			if (f->set == 'J')
				i = calculate_julia_set(f);
			else if (f->set == 'M')
				i = calculate_mandelbrot_set(f);
			else if (f->set == 'B')
				i = calculate_mandelbox_set(f);
			ft_colorize(f, x, y, i);
		}
	}
	mlx_image_to_window(f->mlx, f->img, 0, 0);
}

void	choose_fractal(char *set, t_fractal *fractal)
{
	if (set[0] == 'J')
	{
		if (set[1] == '1')
		{
			fractal->julia_x = 0.285;
			fractal->julia_y = 0.01;
		}
		else if (set[1] == '2')
		{
			fractal->julia_x = 0.0;
			fractal->julia_y = 0.8;
		}
		else if (set[1] == '3')
		{
			fractal->julia_x = -0.8;
			fractal->julia_y = 0.156;
		}
		fractal->set = 'J';
	}
	else if (set[0] == 'M')
		fractal->set = 'M';
	else if (set[0] == 'B')
		fractal->set = 'B';
	mlx_loop_hook(fractal->mlx, draw_fractal, fractal);
}

int32_t	ft_fractal(char *set)
{
	t_fractal	*fractal;

	fractal = malloc(sizeof(t_fractal));
	fractal_init(fractal);
	fractal->mlx = mlx_init(fractal->n, fractal->n, "Fractal", true);
	if (!fractal->mlx)
		return (write(2, "error\n", 6));
	fractal->img = mlx_new_image(fractal->mlx, fractal->n, fractal->n);
	if (!fractal->img
		|| (mlx_image_to_window(fractal->mlx, fractal->img, 0, 0) < 0))
		return (write(2, "error\n", 6));
	choose_fractal(set, fractal);
	mlx_loop_hook(fractal->mlx, my_key_hook, fractal);
	mlx_scroll_hook(fractal->mlx, scrollfunc, fractal);
	mlx_loop_hook(fractal->mlx, color_shift, fractal);
	mlx_loop_hook(fractal->mlx, move_julia, fractal);
	mlx_loop(fractal->mlx);
	mlx_delete_image(fractal->mlx, fractal->img);
	mlx_close_window(fractal->mlx);
	mlx_terminate(fractal->mlx);
	free(fractal);
	return (EXIT_SUCCESS);
}

int32_t	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (!(ft_strncmp(argv[1], "J1", 3)) || !(ft_strncmp(argv[1], "J2", 3))
			|| !(ft_strncmp(argv[1], "J3", 3)) || !(ft_strncmp(argv[1], "M", 2))
			|| !(ft_strncmp(argv[1], "B", 2)))
			return (ft_fractal(argv[1]));
		else
			ft_print_error();
	}
	else
		ft_print_error();
	return (0);
}
