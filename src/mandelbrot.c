/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:05:11 by mnurlybe          #+#    #+#             */
/*   Updated: 2023/07/10 20:45:11 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

int	calculate_mandelbrot_set(t_fractal *f)
{
	int		i;
	double	mr;
	double	mi;
	double	tmp;

	i = 1;
	mr = 0;
	mi = 0;
	while (i <= f->y_maxterations)
	{
		if ((mi * mi + mr * mr) > 4.0)
			break ;
		tmp = 2 * mr * mi + f->b_img;
		mr = mr * mr - mi * mi + f->a_real;
		mi = tmp;
		i++;
	}
	return (i);
}
