/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_fractol.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 16:33:52 by sgalasso          #+#    #+#             */
/*   Updated: 2018/10/24 11:46:45 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_do_frame(t_data *data)
{
	time_t		time_now;
	double		diff;

	data->fract->frame_count++;
	data->fract->time = clock();
	ft_do_fract(data);
	mlx_put_image_to_window(data, data->win_ptr, data->img_ptr, 0, 0);
	time_now = clock();
	diff = (time_now / 10000) - (data->fract->time / 10000);
	if (diff == 0)
		diff = 0.0001;
	data->fract->fps = 1000 / diff;
	if (data->fract->manual == 1)
		ft_put_manual(data);
	else
		ft_put_infos(data);
}

void	ft_start_fract(t_data *data)
{
	data->fract->zoom_on_cursor = 0;
	data->fract->y1 = -1.6;
	data->fract->y2 = 1.6;
	data->fract->x1 = -1.6;
	data->fract->x2 = 1.6;
	if (data->fractale == 1 || data->fractale == 7)
	{
		data->fract->x1 = -2.4;
		data->fract->x2 = 0.9;
	}
	else if (data->fractale == 4)
	{
		data->fract->y2 = 2.4;
		data->fract->x1 = -2.2;
		data->fract->x2 = 1.8;
	}
	else if (data->fractale == 5)
	{
		data->fract->y1 = -2.2;
		data->fract->y2 = 1.0;
		data->fract->x1 = -2.1;
		data->fract->x2 = 1.1;
	}
	ft_do_frame(data);
}

int		ft_init_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_W, WIN_H, "fractol");
	data->img_ptr = mlx_new_image(data->mlx_ptr, IMG_W, IMG_H);
	if (!(data->img_str = (int *)mlx_get_data_addr(data->img_ptr, &(data->bpp),
	&(data->s_l), &(data->endian))))
		return (0);
	mlx_hook(data->win_ptr, 2, 0, ft_event, data);
	mlx_hook(data->win_ptr, 17, 0, ft_close, data);
	mlx_hook(data->win_ptr, 6, 0, ft_mouse, data);
	mlx_hook(data->win_ptr, 4, 0, ft_mouse_btn, data);
	return (1);
}

int		ft_init_fractol(int fractale)
{
	t_data	data;
	int		i;

	i = 0;
	if (!(data.fract = (t_fract *)ft_memalloc(sizeof(t_fract))))
		return (0);
	data.fract->qualite = 12;
	data.fract->nb_thread = 12;
	data.fract->iter_max = 30;
	data.fract->time = clock();
	while (i < 20)
	{
		data.thread[i].data = &data;
		data.thread[i].y_start = i;
		i++;
	}
	if (!(ft_init_mlx(&data)))
	{
		free(data.fract);
		return (0);
	}
	data.fractale = fractale;
	ft_start_fract(&data);
	mlx_loop(&(data.mlx_ptr));
	return (1);
}
