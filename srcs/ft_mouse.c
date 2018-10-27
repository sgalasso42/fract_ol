/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 17:18:46 by sgalasso          #+#    #+#             */
/*   Updated: 2018/10/24 12:33:38 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_mouse_zoom(t_data *data)
{
	if (data->fract->zoom_on_cursor == 1)
	{
		data->fract->x1 += data->fract->key_zoom + data->fract->cursor_x / 2;
		data->fract->x2 += -data->fract->key_zoom + data->fract->cursor_x / 2;
		data->fract->y1 += data->fract->key_zoom + data->fract->cursor_y / 2;
		data->fract->y2 += -data->fract->key_zoom + data->fract->cursor_y / 2;
	}
	else
	{
		data->fract->x1 += data->fract->key_zoom;
		data->fract->x2 -= data->fract->key_zoom;
		data->fract->y1 += data->fract->key_zoom;
		data->fract->y2 -= data->fract->key_zoom;
	}
}

int		ft_mouse_btn(int btn, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (btn == 4)
	{
		data->fract->key_zoom = (data->fract->x2 - data->fract->x1) / 25;
		ft_mouse_zoom(data);
		ft_do_frame(data);
	}
	else if (btn == 5)
	{
		data->fract->key_zoom = (data->fract->x2 - data->fract->x1) / 25;
		data->fract->x1 -= data->fract->key_zoom;
		data->fract->x2 += data->fract->key_zoom;
		data->fract->y1 -= data->fract->key_zoom;
		data->fract->y2 += data->fract->key_zoom;
		ft_do_frame(data);
	}
	if (data->fractale == 1 || data->fractale == 4
	|| data->fractale == 5 || data->fractale == 7)
		return (1);
	if (btn == 1 || btn == 2)
		data->fract->freeze = (data->fract->freeze) == 0 ? 1 : 0;
	return (1);
}

int		ft_mouse(int x, int y, t_data *data)
{
	double	tmpx;
	double	tmpy;

	tmpx = data->fract->mouse_x;
	tmpy = data->fract->mouse_y;
	if (data->fractale == 1 || data->fractale == 4 || data->fractale == 5
	|| data->fractale == 7)
		return (1);
	data->fract->cursor_x = (x - IMG_W / 2) / data->fract->zoom;
	data->fract->cursor_y = (y - IMG_H / 2) / data->fract->zoom;
	if (x > 0 && x < IMG_W && y > 0 && y < IMG_H && data->fract->freeze == 0)
	{
		x -= IMG_W / 2;
		y -= IMG_H / 2;
		data->fract->mouse_x = x / data->fract->zoom;
		data->fract->mouse_y = y / data->fract->zoom;
		if (tmpx != data->fract->mouse_x || tmpy != data->fract->mouse_y)
			ft_do_frame(data);
	}
	return (1);
}
