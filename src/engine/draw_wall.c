/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 09:40:08 by kbaridon          #+#    #+#             */
/*   Updated: 2025/06/04 00:28:06 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "engine/raycast.h"
#include "engine/render.h"
#include "common.h"
#include "system.h"
#include "engine/wall.h"
#include <stdio.h>

static int	get_texture_color(t_img *tex, int x, int y)
{
	char	*pixel;

	pixel = tex->addr + (y * tex->llen + x * (tex->bpp / 8));
	return (*(unsigned int *)pixel);
}

static	t_img	*get_texture(t_system *sys, t_ray *ray)
{
	if (ray->side == 0 && ray->raydir.x > 0)
		return (&sys->game->ea);
	else if (ray->side == 0 && ray->raydir.x < 0)
		return (&sys->game->we);
	else if (ray->side == 1 && ray->raydir.y > 0)
		return (&sys->game->no);
	else
		return (&sys->game->so);
}

static double	get_wall_x(t_system *sys, t_ray *ray, int *line_height)
{
	double	perpdis;
	double	result;

	if (ray->side == 0)
		perpdis = ray->side_dist.x - ray->delta_dist.x;
	else
		perpdis = ray->side_dist.y - ray->delta_dist.y;
	if (perpdis <= 0.000001)
		perpdis = 0.000001;
	*line_height = (int)(WINDOW_HEIGHT / perpdis);
	if (ray->side == 0)
		result = sys->game->player.pos.y / PIXEL_SIZE + perpdis * ray->raydir.y;
	else
		result = sys->game->player.pos.x / PIXEL_SIZE + perpdis * ray->raydir.x;
	result = fmod(result, 1.0);
	if (result < 0)
		result += 1.0;
	return (result);
}

static void	do_pixel(t_wall data, t_img *tex, t_system *sys, int x)
{
	int	i;
	int	color;

	i = data.start_y;
	while (i < data.end_y)
	{
		data.tex_y = (int)data.tex_pos;
		if (data.tex_y < 0)
			data.tex_y = 0;
		if (data.tex_y >= tex->h)
			data.tex_y = tex->h - 1;
		data.tex_pos += data.step;
		color = get_texture_color(tex, data.tex_x, data.tex_y);
		put_pixel(&sys->buffer, x, i, color);
		i++;
	}
}

void	draw_wall(t_system *sys, t_ray *ray, int x)
{
	t_wall	data;
	t_img	*tex;

	data.wall_x = get_wall_x(sys, ray, &data.line_h);
	data.start_y = -data.line_h / 2 + WINDOW_HEIGHT / 2;
	if (data.start_y < 0)
		data.start_y = 0;
	data.end_y = data.line_h / 2 + WINDOW_HEIGHT / 2;
	if (data.end_y >= WINDOW_HEIGHT)
		data.end_y = WINDOW_HEIGHT - 1;
	tex = get_texture(sys, ray);
	data.tex_x = (int)(data.wall_x * (double)tex->w);
	if ((ray->side == 0 && ray->raydir.x > 0) || \
	(ray->side == 1 && ray->raydir.y < 0))
		data.tex_x = tex->w - data.tex_x - 1;
	data.step = (double)tex->h / (double)data.line_h;
	data.tex_pos = (data.start_y - WINDOW_HEIGHT / 2 + data.line_h / 2) \
	* data.step;
	do_floor_and_ceiling(data, sys, x);
	do_pixel(data, tex, sys, x);
}
