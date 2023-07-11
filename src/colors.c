/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:48:58 by mnurlybe          #+#    #+#             */
/*   Updated: 2023/07/11 17:45:10 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

int	rgb(int i)
{
	union u_color	c;

	c.channels[0] = (unsigned char)(sin(0.016 * i + 4) * 125 + 255);
	c.channels[1] = (unsigned char)(sin(0.013 * i + 2) * 125 + 255);
	c.channels[2] = (unsigned char)(sin(0.01 * i + 1) * 125 + 255);
	c.channels[3] = 80;
	return (c.number);
}

void	color_shift(void *p)
{
	t_fractal	*f;

	f = p;
	if (mlx_is_key_down(f->mlx, MLX_KEY_SPACE))
		f->color_shift++;
}

void	ft_colorize(t_fractal *f, int x, int y, int i)
{
	if (i == f->y_maxterations + 1)
		mlx_put_pixel(f->img, x, y, rgb(i + f->color_shift));
	else
		mlx_put_pixel(f->img, x, y, rgb(i + f->color_shift + 200));
}
