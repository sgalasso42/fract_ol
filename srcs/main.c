/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 15:36:17 by sgalasso          #+#    #+#             */
/*   Updated: 2018/10/24 12:40:34 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		ft_ibzero(int *img_str)
{
	int i;

	i = 0;
	while (i < IMG_H * IMG_W)
	{
		img_str[i] = 0;
		i++;
	}
}

void		ft_fill_pixel(t_data *data, int x, int y, int color)
{
	data->img_str[x + y * IMG_W] = color;
}

void		ft_put_usage(void)
{
	ft_putstr("Usage: ./fractol [name]\n-> mandelbrot\n");
	ft_putstr("-> julia\n-> julia_mod\n-> mandelbrot_mod\n");
	ft_putstr("-> burning_ship\n-> burning_julia\n");
	ft_putstr("-> mandelbroken\n-> multijulia\n");
	exit(0);
}

int			ft_close(t_data *data)
{
	free(data->fract);
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(EXIT_SUCCESS);
}

int			main(int argc, char **argv)
{
	int fractale;

	fractale = 1;
	if (argc != 2)
		ft_put_usage();
	else if (ft_strequ(argv[1], "mandelbrot"))
		fractale = 1;
	else if (ft_strequ(argv[1], "julia"))
		fractale = 2;
	else if (ft_strequ(argv[1], "julia_mod"))
		fractale = 3;
	else if (ft_strequ(argv[1], "mandelbrot_mod"))
		fractale = 4;
	else if (ft_strequ(argv[1], "burning_ship"))
		fractale = 5;
	else if (ft_strequ(argv[1], "multijulia"))
		fractale = 6;
	else if (ft_strequ(argv[1], "mandelbroken"))
		fractale = 7;
	else if (ft_strequ(argv[1], "burning_julia"))
		fractale = 8;
	else
		ft_put_usage();
	ft_init_fractol(fractale);
}
