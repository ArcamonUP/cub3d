/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 00:58:31 by achu              #+#    #+#             */
/*   Updated: 2025/05/14 01:11:08 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/image.h"

// Copy pixel from an image to another image
void	put_pixel(t_image *img, int x, int y, unsigned int color)
{
	char	*pixel;

	if (x < 0 || y < 0 || x >= img->w || y >= img->h)
		return ;
	pixel = img->addr + (y * img->llen + x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}

// Get the pixel color RGBA
unsigned int	get_pixel(t_image *img, int x, int y)
{
	char	*pixel;

	if (x < 0 || y < 0 || x >= img->w || y >= img->h)
		return (0);
	pixel = img->addr + (y * img->llen + x * (img->bpp / 8));
	return (*(unsigned int *)pixel);
}

unsigned int	pixel_alpha(int color, float alpha)
{
	return ((int)(alpha * 255) << 24 | color);
}

void	clear_buffer(t_image *buffer, unsigned int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < buffer->h)
	{
		x = 0;
		while (x < buffer->w)
		{
			put_pixel(buffer, x, y, color | 0xFF000000);
			x++;
		}
		y++;
	}
}
