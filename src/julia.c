/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:05:42 by mnurlybe          #+#    #+#             */
/*   Updated: 2023/07/10 20:45:11 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

int	calculate_julia_set(t_fractal *f)
{
	int		i;
	double	tmp;

	i = 1;
	while (i <= f->y_maxterations)
	{
		if ((f->b_img * f->b_img + f->a_real * f->a_real) > 4.0)
			break ;
		tmp = 2 * f->a_real * f->b_img + f->julia_y;
		f->a_real = f->a_real * f->a_real - f->b_img * f->b_img + f->julia_x;
		f->b_img = tmp;
		i++;
	}
	return (i);
}
