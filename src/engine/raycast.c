/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:38:21 by achu              #+#    #+#             */
/*   Updated: 2025/06/03 15:06:54 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "engine/raycast.h"
#include "engine/render.h"
#include "common.h"
#include "system.h"
#include "engine/wall.h"

static t_vec2	pythagora(t_vec2 dir)
{
	t_vec2	delta;

	if (dir.x == 0)
		delta.x = 1e30;
	else
		delta.x = fabs(1.0 / dir.x);
	if (dir.y == 0)
		delta.y = 1e30;
	else
		delta.y = fabs(1.0 / dir.y);
	return (delta);
}

static void	get_sidedist(t_ray *ray, t_player player)
{
	if (ray->raydir.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (player.pos.x / PIXEL_SIZE - ray->grid.x)
			* ray->delta_dist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = ((ray->grid.x + 1.0f) - player.pos.x / PIXEL_SIZE)
			* ray->delta_dist.x;
	}
	if (ray->raydir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (player.pos.y / PIXEL_SIZE - ray->grid.y)
			* ray->delta_dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = ((ray->grid.y + 1.0f) - player.pos.y / PIXEL_SIZE)
			* ray->delta_dist.y;
	}
}

static bool	is_rayhit(char **map, t_ray *ray)
{
	bool		hit;

	hit = false;
	while (!hit)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->grid.x += ray->step.x;
			ray->side_dist.x += ray->delta_dist.x;
			ray->side = 0;
		}
		else
		{
			ray->grid.y += ray->step.y;
			ray->side_dist.y += ray->delta_dist.y;
			ray->side = 1;
		}
		if (map[(int)ray->grid.y][(int)ray->grid.x] == '1')
			hit = true;
	}
	return (hit);
}

void	update_raycasting(t_system *sys)
{
	t_player	player;
	t_ray		ray;
	double		camera;
	int			i;

	i = 0;
	player = sys->game->player;
	while (i < WINDOW_WIDTH)
	{
		camera = 2.0f * i / (double)WINDOW_WIDTH - 1.0f;
		ray.raydir.x = player.dir.x + (-player.dir.y) * 0.9f * camera;
		ray.raydir.y = player.dir.y + player.dir.x * 0.9f * camera;
		ray.delta_dist = pythagora(ray.raydir);
		ray.grid.x = (int)(player.pos.x / PIXEL_SIZE);
		ray.grid.y = (int)(player.pos.y / PIXEL_SIZE);
		printf("%lf:%lf\n", player.pos.x, player.pos.y);
		get_sidedist(&ray, player);
		is_rayhit(sys->grid->map, &ray);
		draw_wall(sys, &ray, i);
		i++;
	}
}
