/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 01:31:21 by achu              #+#    #+#             */
/*   Updated: 2025/05/15 01:38:05 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/render.h"
#include "engine/image.h"
#include "common.h"
#include "system.h"

void	render(t_system *sys)
{
	// t_game	*game;

	// game = sys->game;
	clear_buffer(&sys->buffer, 0x505CB2);
	int y = 0;
	while (sys->grid->map[y])
	{
		int x = 0;
		while (sys->grid->map[y][x])
		{
			if (sys->grid->map[y][x] == WALL)
			{
				draw_square(&sys->buffer,
					(t_rect)
					{
						.pos.x = x * PIXEL_SIZE,
						.pos.y = y * PIXEL_SIZE,
						.size.x = PIXEL_SIZE,
						.size.y = PIXEL_SIZE
					}, RED);
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(sys->window.mlx, sys->window.win, sys->buffer.ptr, 0, 0);
	mlx_do_sync(sys->window.mlx);
}
