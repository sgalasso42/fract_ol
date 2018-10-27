/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 15:31:13 by sgalasso          #+#    #+#             */
/*   Updated: 2018/10/23 15:42:38 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	ft_key_flags(int key, t_data *data)
{
	if (key == 34)
	{
		if (data->fract->manual == 0)
			data->fract->manual = 1;
		else
			data->fract->manual = 0;
		ft_do_frame(data);
	}
	else if (key == 67)
	{
		if (data->fract->zoom_on_cursor == 0)
			data->fract->zoom_on_cursor = 1;
		else
			data->fract->zoom_on_cursor = 0;
		ft_do_frame(data);
	}
	else if (key == 8)
	{
		if (data->fract->color == 4)
			data->fract->color = 0;
		else
			data->fract->color++;
		ft_do_frame(data);
	}
}
