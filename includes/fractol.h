/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 15:37:02 by sgalasso          #+#    #+#             */
/*   Updated: 2018/10/24 12:34:19 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include <math.h>
# include <pthread.h>
# include <time.h>

# define WIN_W 800
# define WIN_H 800
# define IMG_W 800
# define IMG_H 800

typedef struct			s_pos
{
	double	x;
	double	y;
}						t_pos;

typedef struct			s_cplx
{
	double	r;
	double	i;
}						t_cplx;

typedef struct			s_thread
{
	pthread_t		t;
	struct s_data	*data;
	double			y_start;
	t_pos			pos;
	t_cplx			c;
	t_cplx			z;
}						t_thread;

typedef struct			s_fract
{
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	int				nb_thread;
	int				qualite;
	int				iter_max;
	int				freeze;
	double			zoom;
	double			key_zoom;
	int				zoom_on_cursor;
	double			cursor_x;
	double			cursor_y;
	double			mouse_x;
	double			mouse_y;
	int				frame_count;
	time_t			time;
	int				fps;
	int				color;
	int				manual;
}						t_fract;

typedef struct			s_data
{
	int			fractale;
	t_thread	thread[20];
	t_fract		*fract;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			*img_str;
	int			endian;
	int			bpp;
	int			s_l;
}						t_data;

void					ft_ibzero(int *img_str);
int						ft_close(t_data *data);
void					ft_fill_pixel(t_data *data, int x, int y, int color);

int						ft_init_fractol(int fractal);
void					ft_start_fract(t_data *data);
void					ft_do_frame(t_data *data);

void					ft_put_infos(t_data *data);
void					ft_put_manual(t_data *data);

void					ft_key_thread(int key, t_data *data);
void					ft_key_iter(int key, t_data *data);
void					ft_key_space(t_data *data);
void					ft_key_move(int key, t_data *data);
void					ft_key_zoom(int key, t_data *data);
void					ft_key_fract(int key, t_data *data);
void					ft_key_flags(int key, t_data *data);

void					ft_do_fract(t_data *data);
int						ft_iterate(t_thread *thread, int iter);
int						ft_set_color(t_thread *thread, int iter);

void					*ft_mandelbrot(void *arg);
void					*ft_julia(void *arg);
int						ft_mouse_btn(int btn, int x, int y, t_data *data);
int						ft_mouse(int x, int y, t_data *data);
int						ft_event(int key, t_data *data);

#endif
