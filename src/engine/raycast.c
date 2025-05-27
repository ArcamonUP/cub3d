/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:38:21 by achu              #+#    #+#             */
/*   Updated: 2025/05/28 00:59:08 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "engine/render.h"
#include "common.h"
#include "system.h"

static t_vec2	pythagora(t_vec2 dir)
{
	t_vec2	distance;

	distance.x = sqrt(1 + (dir.y * dir.y) / (dir.x * dir.x));
	distance.y = sqrt(1 + (dir.x * dir.x) / (dir.y * dir.y));
	return (distance);
}

void draw_ray(t_img *buf, t_vec2 start, t_vec2 raydir, double max_length, char **map)
{
    for (double i = 0; i < max_length; i += 0.5)
    {
        double x = start.x + raydir.x * i;
        double y = start.y + raydir.y * i;

        if (x < 0 || y < 0)
            break;

        int grid_x = (int)(x / PIXEL_SIZE);
        int grid_y = (int)(y / PIXEL_SIZE);

        if (map[grid_y][grid_x] == '1')
            break;

        put_pixel(buf, (int)x, (int)y, GREEN);
    }
}

void draw_vertical_line(t_img *buf, int x, int y_start, int y_end, uint32_t color)
{
    if (x < 0 || x >= buf->w)
        return;

    if (y_start < 0) y_start = 0;
    if (y_end >= buf->h) y_end = buf->h - 1;

    for (int y = y_start; y <= y_end; y++)
    {
        put_pixel(buf, x, y, color);
    }
}

void	update_raycasting(t_system *sys)
{
	t_player	player;
	t_vec2		delta_dist;
	t_vec2		step;

	t_vec2		raydir;
	double		camera;
	int			side = 0;

	int			i;
	i = 0;
	player = sys->game->player;
	while (i < WINDOW_WIDTH)
	{
		camera = 2.0f * i / (double)WINDOW_WIDTH - 1.0f;
		raydir.x = player.dir.x + (-player.dir.y) * 0.66f * camera;
		raydir.y = player.dir.y + player.dir.x * 0.66f * camera;
	draw_ray(&sys->buffer, player.pos, raydir, 400.0f, sys->grid->map);

		delta_dist = pythagora(raydir);
		t_vec2		grid;
		t_vec2		side_dist;
		
		grid.x = (int)player.pos.x / PIXEL_SIZE;
		grid.y = (int)player.pos.y / PIXEL_SIZE;
		if (raydir.x < 0)
		{
			step.x = -1;
			side_dist.x = (player.pos.x / PIXEL_SIZE - grid.x) * delta_dist.x;
		}
		else
		{
			step.x = 1;
			side_dist.x = ((grid.x + 1.0f) - player.pos.x / PIXEL_SIZE) * delta_dist.x;
		}
		if (raydir.y < 0)
		{
			step.y = -1;
			side_dist.y = (player.pos.y / PIXEL_SIZE - grid.y) * delta_dist.y;
		}
		else
		{
			step.y = 1;
			side_dist.y = ((grid.y + 1.0f) - player.pos.y / PIXEL_SIZE) * delta_dist.y;
		}
	
		bool		hit;
		double		rayDist;
	
		hit = false;
		rayDist = 0.0f;
		while (!hit && rayDist < 1000.0f)
		{
			if (side_dist.x < side_dist.y)
			{
				grid.x += step.x;
				side_dist.x += delta_dist.x;
				rayDist = side_dist.x;
				side = 0;
			}
			else
			{
				grid.y += step.y;
				side_dist.y += delta_dist.y;
				rayDist = side_dist.y;
				side = 1;
			}
			if (sys->grid->map[(int)grid.y][(int)grid.x] == '1')
				hit = true;
		}
		double perpWallDist;
		if(side == 0)
			perpWallDist = side_dist.x - delta_dist.x;
		else
			perpWallDist = side_dist.y - delta_dist.y;

		int lineHeight = (int)(WINDOW_HEIGHT / perpWallDist);
		int drawStart = -lineHeight / 2 + WINDOW_HEIGHT / 2;
		if (drawStart < 0) drawStart = 0;
		
		int drawEnd = lineHeight / 2 + WINDOW_HEIGHT / 2;
		if (drawEnd >= WINDOW_HEIGHT) drawEnd = WINDOW_HEIGHT - 1;
		
		int color = (side == 1) ? CYAN : BLUE;
    	draw_vertical_line(&sys->buffer, i, drawStart, drawEnd, color);
		i++;
	}
}
