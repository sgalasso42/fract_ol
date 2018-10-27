/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_zoom.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 15:29:32 by sgalasso          #+#    #+#             */
/*   Updated: 2018/10/24 12:34:00 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	ft_key_zoom_cursor(t_data *data)
{
	data->fract->x1 += data->fract->key_zoom + data->fract->cursor_x / 2;
	data->fract->x2 += -data->fract->key_zoom + data->fract->cursor_x / 2;
	data->fract->y1 += data->fract->key_zoom + data->fract->cursor_y / 2;
	data->fract->y2 += -data->fract->key_zoom + data->fract->cursor_y / 2;
}

void	ft_key_zoom(int key, t_data *data)
{
	data->fract->key_zoom = (data->fract->x2 - data->fract->x1) / 25;
	if (key == 69)
	{
		if (data->fract->zoom_on_cursor == 1)
			ft_key_zoom_cursor(data);
		else
		{
			data->fract->x1 += data->fract->key_zoom;
			data->fract->x2 -= data->fract->key_zoom;
			data->fract->y1 += data->fract->key_zoom;
			data->fract->y2 -= data->fract->key_zoom;
		}
	}
	else if (key == 78)
	{
		data->fract->x1 -= data->fract->key_zoom;
		data->fract->x2 += data->fract->key_zoom;
		data->fract->y1 -= data->fract->key_zoom;
		data->fract->y2 += data->fract->key_zoom;
	}
	ft_do_frame(data);
}
