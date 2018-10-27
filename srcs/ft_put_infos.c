/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_infos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 15:57:12 by sgalasso          #+#    #+#             */
/*   Updated: 2018/10/23 19:10:11 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_put_manual(t_data *data)
{
	mlx_string_put(data->mlx_ptr,
	data->win_ptr, 10, 10, 0xFFFFFF, "FRACT_OL MANUAL");
	mlx_string_put(data->mlx_ptr,
	data->win_ptr, 10, 40, 0xFFFFFF, "Press [i] to close manual");
	mlx_string_put(data->mlx_ptr,
	data->win_ptr, 10, 80, 0xFFFFFF, "[q][e]           switch fractal");
	mlx_string_put(data->mlx_ptr,
	data->win_ptr, 10, 110, 0xFFFFFF, "[mouse click]    freeze");
	mlx_string_put(data->mlx_ptr,
	data->win_ptr, 10, 140, 0xFFFFFF, "[+][-]           zoom");
	mlx_string_put(data->mlx_ptr,
	data->win_ptr, 10, 170, 0xFFFFFF, "[w][s][a][d]     move");
	mlx_string_put(data->mlx_ptr,
	data->win_ptr, 10, 200, 0xFFFFFF, "[1][2][4][5]     inc iterations");
	mlx_string_put(data->mlx_ptr,
	data->win_ptr, 10, 230, 0xFFFFFF, "[^][v][<][>]     threads managing");
	mlx_string_put(data->mlx_ptr,
	data->win_ptr, 10, 260, 0xFFFFFF, "[c]              change color set");
	mlx_string_put(data->mlx_ptr,
	data->win_ptr, 10, 290, 0xFFFFFF, "[*]              change zoom mode");
	mlx_string_put(data->mlx_ptr,
	data->win_ptr, 10, 320, 0xFFFFFF, "[space]          reset");
}

void	ft_put_name(t_data *data)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 10, 0xFFFFFF, "FRACTALE");
	if (data->fractale == 1)
		mlx_string_put(data->mlx_ptr,
		data->win_ptr, 110, 10, 0xFFFFFF, "MANDELBROT");
	else if (data->fractale == 2)
		mlx_string_put(data->mlx_ptr,
		data->win_ptr, 110, 10, 0xFFFFFF, "JULIA");
	else if (data->fractale == 3)
		mlx_string_put(data->mlx_ptr,
		data->win_ptr, 110, 10, 0xFFFFFF, "JULIA_MOD");
	else if (data->fractale == 4)
		mlx_string_put(data->mlx_ptr,
		data->win_ptr, 110, 10, 0xFFFFFF, "MANDELBROT_MOD");
	else if (data->fractale == 6)
		mlx_string_put(data->mlx_ptr,
		data->win_ptr, 110, 10, 0xFFFFFF, "MULTIJULIA");
	else if (data->fractale == 7)
		mlx_string_put(data->mlx_ptr,
		data->win_ptr, 110, 10, 0xFFFFFF, "MANDELBROKEN");
	else if (data->fractale == 5)
		mlx_string_put(data->mlx_ptr,
		data->win_ptr, 110, 10, 0xFFFFFF, "BURNING_SHIP");
	else if (data->fractale == 8)
		mlx_string_put(data->mlx_ptr,
		data->win_ptr, 110, 10, 0xFFFFFF, "BURNING_JULIA");
}

void	ft_put_var(t_data *data)
{
	char	*val;

	if (!(val = ft_itoa(data->fract->iter_max)))
		ft_close(data);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 130, 135, 0xFFFFFF, val);
	free(val);
	if (!(val = ft_itoa(data->fract->nb_thread)))
		ft_close(data);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 130, 165, 0xFFFFFF, val);
	free(val);
	if (!(val = ft_itoa(data->fract->qualite)))
		ft_close(data);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 94, 165, 0xFFFFFF, val);
	free(val);
	if (!(val = ft_itoa(data->fract->frame_count)))
		ft_close(data);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 120, 210, 0xFFFFFF, val);
	free(val);
	if (!(val = ft_itoa(data->fract->fps)))
		ft_close(data);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 60, 240, 0xFFFFFF, val);
	free(val);
}

void	ft_put_infos(t_data *data)
{
	ft_put_name(data);
	mlx_string_put(data->mlx_ptr,
	data->win_ptr, 10, 40, 0xFFFFFF, "Press [i] to open manual");
	if (data->fract->zoom_on_cursor == 0)
		mlx_string_put(data->mlx_ptr,
		data->win_ptr, 10, 85, 0xFFFFFF, "Zoom : center");
	else
		mlx_string_put(data->mlx_ptr,
		data->win_ptr, 10, 85, 0xFFFFFF, "Zoom : pointer");
	mlx_string_put(data->mlx_ptr,
	data->win_ptr, 10, 135, 0xFFFFFF, "Iterations");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 165, 0xFFFFFF, "Threads");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 105, 165, 0xFFFFFF, " / ");
	mlx_string_put(data->mlx_ptr,
	data->win_ptr, 10, 210, 0xFFFFFF, "nb frames");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 240, 0xFFFFFF, "FPS");
	ft_put_var(data);
}
