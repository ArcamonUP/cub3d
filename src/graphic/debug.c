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

#include <math.h>
#include "engine/image.h"
#include "engine/render.h"
#include "engine/vector.h"
#include "common.h"

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

void	draw_circle(t_img *image, t_vec2 start, int radius)
{
	int			x;
	int			y;
	int			dst;

	start.x = start.x / 2;
	start.y = start.y / 2;
	y = -radius;
	while (y <= radius)
	{
		dst = (int)sqrt((radius * radius) - (y * y));
		x = start.x - dst;
		while (x <= start.x + dst)
		{
			put_pixel(image, x, start.y + y, MAGENTA);
			x++;
		}
		y++;
	}
}

void draw_stripe(t_img *image, int x, int start_y, int end_y, uint32_t color)
{
	int	y;

	if (x < 0 || image->w <= x)
		return ;
	if (start_y < 0)
		start_y = 0;
	if (end_y >= image->h)
		end_y = image->h - 1;
	y = start_y;
	while (y <= end_y)
	{
		put_pixel(image, x, y, color);
		y++;
	}
}
