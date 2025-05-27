/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:38:21 by achu              #+#    #+#             */
/*   Updated: 2025/05/27 17:52:02 by achu             ###   ########.fr       */
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

		delta_dist = pythagora(raydir);
		t_vec2		grid;
		t_vec2		side_dist;
		
		grid.x = (int)player.pos.x / PIXEL_SIZE;
		grid.y = (int)player.pos.y / PIXEL_SIZE;
		if (player.dir.x < 0)
		{
			step.x = -1;
			side_dist.x = (player.pos.x / PIXEL_SIZE - grid.x) * delta_dist.x;
		}
		else
		{
			step.x = 1;
			side_dist.x = ((grid.x + 1.0f) - player.pos.x / PIXEL_SIZE) * delta_dist.x;
		}
		if (player.dir.y < 0)
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
		while (!hit && rayDist < 100.0f)
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
		if (hit)
		{
			double	l;
			t_vec2	length;
			if (side == 0)
			{
				l = side_dist.x - delta_dist.x;
			}
			else
			{
				l = side_dist.y - delta_dist.y;
			}
			length.x = player.pos.x + raydir.x * l * PIXEL_SIZE;
			length.y = player.pos.y + raydir.y * l * PIXEL_SIZE;
			draw_line(&sys->buffer, player.pos, length);
		}
		i++;
	}
}
