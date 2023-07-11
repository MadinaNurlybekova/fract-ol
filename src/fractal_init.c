/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 20:02:48 by mnurlybe          #+#    #+#             */
/*   Updated: 2023/07/11 17:42:22 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

void	fractal_init(t_fractal *fractal)
{
	fractal->n = 500;
	fractal->y_maxterations = 500;
	fractal->julia_x = -0.7269;
	fractal->julia_y = 0.1889;
	fractal->y_min = -2.0;
	fractal->x_min = -2.0;
	fractal->x_max = 2.0;
	fractal->y_max = 2.0;
	fractal->color_shift = 50;
}
