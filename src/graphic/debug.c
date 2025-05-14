/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 01:10:02 by achu              #+#    #+#             */
/*   Updated: 2025/05/14 12:31:08 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/image.h"
#include "engine/render.h"
#include "engine/vector.h"

void	draw_bg(t_img *buffer)
{
	uint32_t	y;
	uint32_t	x;

	y = 0;
	while (y < 180)
	{
		x = 0;
		while (x < 320)
		{
			put_pixel(buffer, x, y, 0xFF191919);
			x++;
		}
		y++;
	}
}

// Draw the entire square into the screen
void	draw_square(t_img *image, t_rect rect, unsigned int color)
{
	float			alpha;
	unsigned int	faded;
	uint32_t		y;
	uint32_t		x;

	y = rect.pos.y;
	while (y < rect.pos.y + rect.size.y)
	{
		x = rect.pos.x;
		while (x < rect.pos.x + rect.size.x)
		{
			alpha = 1.0f;
			if ((color & 0x00FFFFFF) != 0)
			{
				faded = pixel_alpha(color, alpha);
				if (alpha > 0.0f)
					put_pixel(image, x, y, faded);
			}
			x++;
		}
		y++;
	}
}

// Draw the border of the rect into the screen
void	draw_rect(t_img *image, t_rect rect, unsigned int color)
{
	unsigned int	faded;
	uint32_t		y;
	uint32_t		x;

	y = rect.pos.y;
	while (y < rect.pos.y + rect.size.y)
	{
		x = rect.pos.x;
		while (x < rect.pos.x + rect.size.x)
		{
			if (y < rect.pos.y + 1 || y > rect.pos.y + rect.size.y - 2
				|| x < rect.pos.x + 1 || x > rect.pos.x + rect.size.x - 2)
			{
				if ((color & 0x00FFFFFF) != 0)
				{
					faded = pixel_alpha(color, 1.0f);
					put_pixel(image, x, y, faded);
				}
			}
			x++;
		}
		y++;
	}
}

void	draw_line(t_vec2 start, t_vec2 end)
{
	float	dx;
	float	dy;
	float	m;

	dx = end.x - start.x;
	dy = end.y - start.y;
	m = dx / dy;
	
}
