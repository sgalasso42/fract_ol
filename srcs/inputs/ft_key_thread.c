/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 15:24:12 by sgalasso          #+#    #+#             */
/*   Updated: 2018/10/23 19:47:45 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	ft_key_thread(int key, t_data *data)
{
	ft_ibzero(data->img_str);
	if (key == 124 && data->fract->qualite < data->fract->nb_thread)
	{
		data->fract->qualite++;
		ft_do_frame(data);
	}
	else if (key == 123 && data->fract->qualite > 3)
	{
		data->fract->qualite--;
		ft_do_frame(data);
	}
	else if (key == 126 && data->fract->nb_thread < 20)
	{
		data->fract->nb_thread++;
		data->fract->qualite++;
		ft_do_frame(data);
	}
	else if (key == 125 && data->fract->nb_thread > 3)
	{
		data->fract->nb_thread--;
		if (data->fract->qualite > 3)
			data->fract->qualite--;
		ft_do_frame(data);
	}
}
