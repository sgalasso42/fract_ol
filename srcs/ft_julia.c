/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 19:40:11 by sgalasso          #+#    #+#             */
/*   Updated: 2018/10/23 19:40:53 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			*ft_julia(void *arg)
{
	int			i;
	int			iter;
	int			color;
	t_thread	*thread;

	i = 0;
	thread = (t_thread *)arg;
	thread->c.r = thread->data->fract->mouse_x;
	thread->c.i = thread->data->fract->mouse_y;
	thread->pos.y = thread->y_start;
	while (i < IMG_H / thread->data->fract->nb_thread)
	{
		thread->pos.x = 0;
		while (thread->pos.x < IMG_W)
		{
			iter = ft_iterate(thread, 0);
			color = ft_set_color(thread, iter);
			ft_fill_pixel(thread->data, thread->pos.x, thread->pos.y, color);
			thread->pos.x++;
		}
		thread->pos.y += thread->data->fract->nb_thread;
		i++;
	}
	pthread_exit(0);
}
