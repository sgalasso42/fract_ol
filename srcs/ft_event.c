/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 17:09:58 by sgalasso          #+#    #+#             */
/*   Updated: 2018/10/24 10:42:21 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		ft_event(int key, t_data *data)
{
	if (key == 53)
		ft_close(data);
	else if (key >= 123 && key <= 126)
		ft_key_thread(key, data);
	else if (key == 83 || key == 84 || key == 86 || key == 87)
		ft_key_iter(key, data);
	else if (key == 49)
		ft_key_space(data);
	else if ((key >= 0 && key <= 2) || key == 13)
		ft_key_move(key, data);
	else if (key == 69 || key == 78)
		ft_key_zoom(key, data);
	else if (key == 12 || key == 14)
		ft_key_fract(key, data);
	else if (key == 34 || key == 67 || key == 8)
		ft_key_flags(key, data);
	return (1);
}
