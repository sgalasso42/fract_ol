/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 15:28:38 by sgalasso          #+#    #+#             */
/*   Updated: 2018/10/23 15:43:53 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	ft_key_move(int key, t_data *data)
{
	if (key == 13)
	{
		data->fract->y1 -= (data->fract->x2 - data->fract->x1) / 25;
		data->fract->y2 -= (data->fract->x2 - data->fract->x1) / 25;
		ft_do_frame(data);
	}
	else if (key == 1)
	{
		data->fract->y1 += (data->fract->x2 - data->fract->x1) / 25;
		data->fract->y2 += (data->fract->x2 - data->fract->x1) / 25;
		ft_do_frame(data);
	}
	else if (key == 2)
	{
		data->fract->x1 += (data->fract->x2 - data->fract->x1) / 25;
		data->fract->x2 += (data->fract->x2 - data->fract->x1) / 25;
		ft_do_frame(data);
	}
	else if (key == 0)
	{
		data->fract->x1 -= (data->fract->x2 - data->fract->x1) / 25;
		data->fract->x2 -= (data->fract->x2 - data->fract->x1) / 25;
		ft_do_frame(data);
	}
}
