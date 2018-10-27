/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_fract.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 15:30:25 by sgalasso          #+#    #+#             */
/*   Updated: 2018/10/23 15:42:50 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	ft_key_fract(int key, t_data *data)
{
	if (key == 12)
	{
		if (data->fractale > 1)
			data->fractale--;
		else
			data->fractale = 8;
		data->fract->iter_max = 30;
		ft_start_fract(data);
	}
	else if (key == 14)
	{
		if (data->fractale < 8)
			data->fractale++;
		else
			data->fractale = 1;
		data->fract->iter_max = 30;
		ft_start_fract(data);
	}
}
