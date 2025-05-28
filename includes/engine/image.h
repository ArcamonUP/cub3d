/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:47:31 by achu              #+#    #+#             */
/*   Updated: 2025/05/14 00:34:20 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# include <stdbool.h>
# include <stdint.h>
# include "window.h"

# define PIXEL_SIZE	32
# define IMG_NO		"../assets/no.xpm"
# define IMG_SO		"../assets/so.xpm"
# define IMG_WE		"../assets/we.xpm"
# define IMG_EA		"../assets/ea.xpm"

typedef struct s_img
{
	t_display	screen;
	int			w;
	int			h;
	void		*ptr;
	char		*addr;
	int			bpp;
	int			llen;
	int			endian;
	int			error;
}	t_img;

typedef struct s_animation
{
	int32_t	width;
	int32_t	height;
	int32_t	col;
	int32_t	row;
	int32_t	frame_count;
	int32_t	current_frame;
	float	frame_duration;
	float	frame_timer;
	bool	loop;
}	t_animation;

typedef struct s_sprite
{
	t_img		img;
	t_animation	anim;
	bool		is_mirrored;
}	t_sprite;

t_img			new_xpm(t_display window, char *file);
t_img			new_img(t_display window, int h, int w);
t_img			new_img_alpha(t_display window, int w, int h);
void			destroy_img(t_img image);

void			pixel_scale(t_img *src, t_img *dst, int scale);
void			put_pixel(t_img *img, int x, int y, unsigned int color);
unsigned int	pixel_alpha(int color, float alpha);
uint32_t		get_pixel(t_img *img, int x, int y);
void			clear_buffer(t_img *buffer, unsigned int color);

void			update_frame(t_animation *anim, double delta);

#endif