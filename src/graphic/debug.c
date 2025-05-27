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

void	draw_line(t_img *image, t_vec2 start, t_vec2 end)
{
	int		dx;
	int		dy;
	int		step;

	dx = (int)end.x - (int)start.x;
	dy = (int)end.y - (int)start.y;
	if (abs(dx) > abs(dy))
		step = abs(dx);
	else
		step = abs(dy);
	float	inc_x = (float)dx / (float)step;
	float	inc_y = (float)dy / (float)step;
	int	i = 0;
	float	x = start.x;
	float	y = start.y;
	while (i < step)
	{
		put_pixel(image, x, y, GREEN);
		x += inc_x;
		y += inc_y;
		i++;
	}
}

void	draw_circle(t_img *image, t_vec2 start, int radius)
{
	int			x;
	int			y;
	int			dst;

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
