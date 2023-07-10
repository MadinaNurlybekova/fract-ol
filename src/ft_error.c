/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:16:51 by mnurlybe          #+#    #+#             */
/*   Updated: 2023/07/10 21:19:58 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

// void	ft_error(void)
// {
// 	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
// 	exit(EXIT_FAILURE);
// }

void	ft_print_error(void)
{
	ft_printf("\nWrong input!\n");
	ft_printf("\n===== Available Fractal Sets =====\n\n");
	ft_printf("Type M to display Mandelbrot set\n");
	ft_printf("Type J1, J2 or J3 to display Julia set\n");
	ft_printf("Type B to display Mandelbox set\n\n");
	ft_printf("===== Additional features ======\n\n");
	ft_printf("Z, X, C and V: change Julia set parameters\n");
	ft_printf("SPACE KEY: color shift\n");
	ft_printf("ARROWS KEYS: move the view\n");
	ft_printf("MOUSE SCROLL: zoom in and out\n\n");
}
