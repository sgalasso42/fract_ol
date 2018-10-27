/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_space.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 15:27:37 by sgalasso          #+#    #+#             */
/*   Updated: 2018/10/23 15:28:26 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	ft_key_space(t_data *data)
{
	ft_ibzero(data->img_str);
	data->fract->iter_max = 30;
	data->fract->nb_thread = 12;
	data->fract->qualite = 12;
	ft_start_fract(data);
}
