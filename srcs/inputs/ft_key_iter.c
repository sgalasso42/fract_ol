/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_iter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 15:26:31 by sgalasso          #+#    #+#             */
/*   Updated: 2018/10/23 15:43:03 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	ft_key_iter(int key, t_data *data)
{
	if (key == 83 || key == 86)
	{
		if (key == 83)
			data->fract->iter_max += 10;
		else
			data->fract->iter_max += 1;
		ft_do_frame(data);
	}
	else if (key == 84 || key == 87)
	{
		if (data->fract->iter_max > 10)
		{
			if (key == 84)
				data->fract->iter_max -= 10;
			else
				data->fract->iter_max -= 1;
			if (data->fract->iter_max < 10)
				data->fract->iter_max = 10;
			ft_do_frame(data);
		}
	}
}
