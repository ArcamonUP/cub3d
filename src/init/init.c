/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:30:04 by kbaridon          #+#    #+#             */
/*   Updated: 2025/05/14 15:39:24 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "libft.h"
#include <mlx.h>

t_img	create_image(void *mlx, char *path)
{
	t_img	image;

	image.error = 0;
	image.ptr = mlx_xpm_file_to_image(mlx, path, &image.w, &image.h);
	if (!image.ptr)
	{
		image.error = 1;
		return (image);
	}
	image.addr = mlx_get_data_addr(image.ptr, &image.bpp, \
	&image.llen, &image.endian);
	if (!image.addr)
		image.error = 1;
	return (image);
}

// t_vars	init(t_data *data)
// {
// 	t_vars	var;

// 	var.error = 0;
// 	var.mlx = mlx_init();
// 	var.win = create_window(var.mlx);
// 	var.ea = create_image(var.mlx, data->ea_path);
// 	var.no = create_image(var.mlx, data->no_path);
// 	var.so = create_image(var.mlx, data->so_path);
// 	var.we = create_image(var.mlx, data->we_path);
// 	if (var.ea.error || var.no.error || var.so.error || var.we.error)
// 		var.error = 1;
// 	var.ceiling_color = get_color(data->ceiling_color);
// 	var.floor_color = get_color(data->floor_color);
// 	if (var.ceiling_color == -1 || var.floor_color == -1)
// 		var.error = 1;
// 	var.player = init_player(data->map);
// 	var.map = cp_tab_no_player(data->map, var.player.pos);
// 	if (!var.map)
// 		var.error = 1;
// 	*data = destroy_data(*data);
// 	return (var);
// }
