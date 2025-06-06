/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 01:31:21 by achu              #+#    #+#             */
/*   Updated: 2025/06/04 00:21:46 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/render.h"
#include "engine/image.h"
#include "common.h"
#include "system.h"

static void	render_wall(t_system *sys)
{
	int	x;
	int	y;

	y = 0;
	while (sys->grid->map[y])
	{
		x = 0;
		while (sys->grid->map[y][x])
		{
			if (sys->grid->map[y][x] == WALL)
			{
				draw_square(&sys->buffer,
					(t_rect){
					.pos.x = x * PIXEL_SIZE / 2,
					.pos.y = y * PIXEL_SIZE / 2,
					.size.x = PIXEL_SIZE / 2,
					.size.y = PIXEL_SIZE / 2
				}, RED);
			}
			x++;
		}
		y++;
	}
}

void	render(t_system *sys)
{
	t_game	*game;

	game = sys->game;
	render_wall(sys);
	draw_circle(&sys->buffer, game->player.pos, 5);
	mlx_put_image_to_window(sys->window.mlx,
		sys->window.win, sys->buffer.ptr, 0, 0);
	mlx_do_sync(sys->window.mlx);
}
