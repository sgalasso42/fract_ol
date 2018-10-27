/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 19:38:06 by sgalasso          #+#    #+#             */
/*   Updated: 2018/10/23 19:40:04 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			*ft_mandelbrot(void *arg)
{
	int			i;
	int			iter;
	int			color;
	t_thread	*thread;

	i = 0;
	thread = (t_thread *)arg;
	thread->pos.y = thread->y_start;
	while (i < IMG_H / thread->data->fract->nb_thread)
	{
		thread->pos.x = -1;
		while (++thread->pos.x < IMG_W)
		{
			thread->c.r = (thread->pos.x / thread->data->fract->zoom
			+ thread->data->fract->x1);
			thread->c.i = (thread->pos.y / thread->data->fract->zoom
			+ thread->data->fract->y1);
			iter = ft_iterate(thread, 0);
			color = ft_set_color(thread, iter);
			ft_fill_pixel(thread->data, thread->pos.x, thread->pos.y, color);
		}
		thread->pos.y += thread->data->fract->nb_thread;
		i++;
	}
	pthread_exit(0);
}
