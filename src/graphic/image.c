/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 00:51:22 by achu              #+#    #+#             */
/*   Updated: 2025/05/14 00:54:50 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/image.h"
#include "common.h"

t_image	new_img(t_display window, int w, int h)
{
	t_image	image;

	image.error = 0;
	image.w = w;
	image.h = h;
	image.screen = window;
	image.ptr = mlx_new_image(window.mlx, w, h);
	if (!image.ptr)
	{
		image.error = 1;
		return (image);
	}
	image.addr = mlx_get_data_addr(image.ptr,
			&(image.bpp), &(image.llen), &(image.endian));
	if (!image.addr)
	{
		image.error = 1;
		return (destroy_img(image), image);
	}
	return (image);
}

void	destroy_img(t_image image)
{
	if (image.ptr && image.screen.mlx)
		mlx_destroy_image(image.screen.mlx, image.ptr);
}
