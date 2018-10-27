/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_fract.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 14:30:56 by sgalasso          #+#    #+#             */
/*   Updated: 2018/10/23 19:43:46 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int				ft_set_color(t_thread *thread, int iter)
{
	const int	palette_1[18] = {0xEF2546, 0xEE2F42, 0xEE3A3F, 0xEE453C,
	0xEE4F39, 0xEE5A36, 0xEE6533, 0xEE6F2F, 0xEE7A2C, 0xEE8529, 0xEE8F26,
	0xEE9A23, 0xEEA520, 0xEEAF1C, 0xEEBA19, 0xEEC516, 0xEECF13, 0xEEDA10};
	const int	palette_2[18] = {0x3D00C7, 0x3A0CC9, 0x3719CB, 0x3425CD,
	0x3232CF, 0x2F3FD1, 0x2C4BD3, 0x2A58D6, 0x2765D8, 0x2471DA, 0x227EDC,
	0x1F8ADE, 0x1C97E0, 0x1AA4E3, 0x17B0E5, 0x14BDE7, 0x12CAE9, 0x0FD6EB};
	const	int palette_3[13] = {0x5d19ed, 0x681ce3, 0x7220d8, 0x7d23ce,
	0x8826c4, 0x922aba, 0x9d2db0, 0xa830a5, 0xb2349b, 0xbd3791, 0xc83a97,
	0xd23e7c, 0xdd4172};
	const int	palette_4[4] = {0x3108A4, 0x2C0794, 0x270683, 0x220673};

	if (iter != thread->data->fract->iter_max)
	{
		if (thread->data->fract->color == 0)
			return (iter * 765 / thread->data->fract->iter_max);
		else if (thread->data->fract->color == 1)
			return (palette_1[iter % 18]);
		else if (thread->data->fract->color == 2)
			return (palette_2[iter % 18]);
		else if (thread->data->fract->color == 3)
			return (palette_3[iter % 13]);
		else if (thread->data->fract->color == 4)
			return (palette_4[iter % 4]);
	}
	return (0x0);
}

void			ft_calc_cplx(t_thread *thread)
{
	thread->z.r = thread->pos.x / thread->data->fract->zoom;
	thread->z.i = thread->pos.y / thread->data->fract->zoom;
	thread->z.r += thread->data->fract->x1;
	thread->z.i += thread->data->fract->y1;
	if (thread->data->fractale == 5 || thread->data->fractale == 6
	|| thread->data->fractale == 7 || thread->data->fractale == 8)
	{
		thread->z.r = ft_abs(thread->z.r);
		thread->z.i = ft_abs(thread->z.i);
	}
}

void			ft_calc_iterate(t_thread *thread, double zrsq, double zisq)
{
	if (thread->data->fractale == 3 || thread->data->fractale == 4)
		thread->z.i = ft_sq(thread->z.r * thread->z.i) - zrsq - zisq;
	else
		thread->z.i = ft_sq(thread->z.r + thread->z.i) - zrsq - zisq;
	thread->z.i += thread->c.i;
	thread->z.r = zrsq - zisq + thread->c.r;
	if (thread->data->fractale == 5 || thread->data->fractale == 8)
	{
		thread->z.i = ft_abs(thread->z.i);
		thread->z.r = ft_abs(thread->z.r);
	}
}

int				ft_iterate(t_thread *thread, int iter)
{
	double		zrsq;
	double		zisq;
	double		p;

	ft_calc_cplx(thread);
	zrsq = ft_sq(thread->z.r);
	zisq = ft_sq(thread->z.i);
	if (thread->data->fractale == 1)
	{
		p = sqrt(ft_sq((thread->z.r - (0.25))) + zisq);
		if (thread->z.r < p - (2 * ft_sq(p)) + (0.25))
			return (thread->data->fract->iter_max);
		if (ft_sq(thread->z.r + 1) + zisq < (0.0625))
			return (thread->data->fract->iter_max);
	}
	while (zrsq + zisq < 4 && iter < thread->data->fract->iter_max)
	{
		ft_calc_iterate(thread, zrsq, zisq);
		zrsq = ft_sq(thread->z.r);
		zisq = ft_sq(thread->z.i);
		iter++;
	}
	return (iter);
}

void			ft_do_fract(t_data *data)
{
	int i;

	i = 0;
	data->fract->zoom = IMG_W / (data->fract->x2 - data->fract->x1);
	while (i < data->fract->nb_thread)
	{
		if (i < data->fract->qualite)
		{
			if (data->fractale == 2 || data->fractale == 3
			|| data->fractale == 6 || data->fractale == 8)
				pthread_create(&(data->thread[i].t)
				, NULL, ft_julia, &(data->thread[i]));
			else if (data->fractale == 1 || data->fractale == 4
			|| data->fractale == 7 || data->fractale == 5)
				pthread_create(&(data->thread[i].t)
				, NULL, ft_mandelbrot, &(data->thread[i]));
		}
		i++;
	}
	i = -1;
	while (++i < data->fract->nb_thread)
	{
		if (i <= data->fract->qualite)
			pthread_join(data->thread[i].t, 0);
	}
}
