/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbox.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:48:17 by mnurlybe          #+#    #+#             */
/*   Updated: 2023/07/10 20:45:11 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

double	box_fold(double v)
{
	if (v > 1.0)
		v = 2.0 - v;
	else if (v < -1.0)
		v = -2.0 - v;
	return (v);
}

double	magnitude(double m, double v)
{
	double	scale;

	scale = -1.1;
	if (m < 0.5)
		v *= 4;
	else if (m < 1.0)
		v = v / (m * m);
	else
		v = scale * v;
	return (v);
}

int	calculate_mandelbox_set(t_fractal *f)
{
	int		i;
	double	scale;
	double	mag;
	double	x_real;
	double	y_img;

	i = 1;
	scale = 2.0;
	x_real = f->a_real;
	y_img = f->b_img;
	while (i <= f->y_maxterations)
	{
		x_real = box_fold(x_real);
		y_img = box_fold(y_img);
		mag = sqrt(x_real * x_real + y_img * y_img);
		if (x_real * x_real + y_img * y_img > 4.0)
			break ;
		x_real = scale * magnitude(mag, x_real) + f->a_real;
		y_img = scale * magnitude(mag, y_img) + f->b_img;
		i++;
	}
	return (i);
}
