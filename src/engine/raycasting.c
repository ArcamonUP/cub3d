/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:38:21 by achu              #+#    #+#             */
/*   Updated: 2025/05/27 15:48:20 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "engine/render.h"
#include "common.h"
#include "system.h"

static t_vec2	pythagora(t_vec2 dir)
{
	t_vec2	delta_distance;

	delta_distance.x = sqrt(1 + (dir.y * dir.y) / (dir.x * dir.x));
	delta_distance.y = sqrt(1 + (dir.x * dir.x) / (dir.y * dir.y));
	return (delta_distance);
}

void	update_raycasting(t_system *sys)
{
	t_player	player;
	t_vec2		delta_dist;

	t_vec2		step;
	int	i = 0;

	player = sys->game->player;
	while (i < 120)
	{
		double	cam = 2.0f * i / (double)120.0f - 1.0f;
		t_vec2		raydir;
		raydir.x = player.dir.x + (-player.dir.y) * 0.66f * cam;
		raydir.y = player.dir.y + player.dir.x * 0.66f * cam;
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
			}
			else
			{
				grid.y += step.y;
				side_dist.y += delta_dist.y;
				rayDist = side_dist.y;
			}
			if (sys->grid->map[(int)grid.y][(int)grid.x] == '1')
				hit = true;
		}
		if (hit)
		{
			t_vec2	length = (t_vec2){
				.x = player.pos.x + raydir.x * rayDist * PIXEL_SIZE,
				.y = player.pos.y + raydir.y * rayDist * PIXEL_SIZE,
			};
			draw_line(&sys->buffer, player.pos, length);
		}
		i++;
	}
}