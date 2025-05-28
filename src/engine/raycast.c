/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:38:21 by achu              #+#    #+#             */
/*   Updated: 2025/05/28 17:38:08 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "engine/raycast.h"
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

static void	draw_wall(t_img *image, t_ray *ray, int x)
{
	double		perpwall_dist;
	int			line_height;
	int			start_y;
	int			end_y;
	int			color;

	if (ray->side == 0)
		perpwall_dist = ray->side_dist.x - ray->delta_dist.x;
	else
		perpwall_dist = ray->side_dist.y - ray->delta_dist.y;
	line_height = (int)(WINDOW_HEIGHT / perpwall_dist);
	start_y = -line_height / 2 + WINDOW_HEIGHT / 2;
	if (start_y < 0)
		start_y = 0;
	end_y = line_height / 2 + WINDOW_HEIGHT / 2;
	if (end_y >= WINDOW_HEIGHT)
		end_y = WINDOW_HEIGHT - 1;
	if (ray->side == 1)
		color = CYAN;
	else
		color = BLUE;
	draw_stripe(image, x, start_y, end_y, color);
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
		ray.raydir.x = player.dir.x + (-player.dir.y) * 0.66f * camera;
		ray.raydir.y = player.dir.y + player.dir.x * 0.66f * camera;
		ray.delta_dist = pythagora(ray.raydir);
		ray.grid.x = (int)player.pos.x / PIXEL_SIZE;
		ray.grid.y = (int)player.pos.y / PIXEL_SIZE;
		get_sidedist(&ray, player);
		is_rayhit(sys->grid->map, &ray);
		draw_wall(&sys->buffer, &ray, i);
		i++;
	}
}
