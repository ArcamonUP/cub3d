/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor_ceiling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaridon <kbaridon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 11:12:36 by kbaridon          #+#    #+#             */
/*   Updated: 2025/05/31 11:55:39 by kbaridon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "engine/raycast.h"
#include "engine/render.h"
#include "common.h"
#include "system.h"
#include "engine/wall.h"

#include <stdio.h>

unsigned int	to_hexa(const char *rgb, int r, int g, int b)
{
	int	i;

	i = 0;
	while (rgb[i] >= '0' && rgb[i] <= '9')
	{
		r = r * 10 + (rgb[i] - '0');
		i++;
	}
	i++;
	while (rgb[i] >= '0' && rgb[i] <= '9')
	{
		g = g * 10 + (rgb[i] - '0');
		i++;
	}
	i++;
	while (rgb[i] >= '0' && rgb[i] <= '9')
	{
		b = b * 10 + (rgb[i] - '0');
		i++;
	}
	return (((unsigned int)r << 16) | ((unsigned int)g << 8) | (unsigned int)b);
}

void	do_floor_and_ceiling(t_wall data, t_system *sys, int x)
{
	int	i;

	i = 0;
	while (i < data.start_y)
	{
		put_pixel(&sys->buffer, x, i, \
			to_hexa(sys->grid->ceiling_color, 0, 0, 0));
		i++;
	}
	i = data.end_y;
	while (i < WINDOW_HEIGHT)
	{
		put_pixel(&sys->buffer, x, i, to_hexa(sys->grid->floor_color, 0, 0, 0));
		i++;
	}
}
