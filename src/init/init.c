/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaridon <kbaridon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:30:04 by kbaridon          #+#    #+#             */
/*   Updated: 2025/05/05 13:33:39 by kbaridon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include <mlx.h>

t_img	create_image(void *mlx, char *path)
{
	t_img	image;

	image.error = 0;
	image.img = mlx_xpm_file_to_image(mlx, path, &image.width, &image.heigh);
	if (!image.img)
	{
		image.error = 1;
		return (image);
	}
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, \
	&image.line_length, &image.endian);
	if (!image.addr)
		image.error = 1;
	return (image);
}

void	*create_window(void *mlx)
{
	void	*mlx_win;

	mlx_win = mlx_new_window(mlx, 200, 200, "cub3d");
	//200x200 a changer ici
	return (mlx_win);
}

int	get_color(char *rgb_str)
{
	int	r;
	int	g;
	int	b;
	int	i;

	i = 0;
	r = get_value(rgb_str, &i);
	if (r == -1)
		return (-1);
	g = get_value(rgb_str, &i);
	if (g == -1)
		return (-1);
	b = get_value(rgb_str, &i);
	if (b == -1)
		return (-1);
	return ((r << 16) | (g << 8) | b);
}

t_player	init_player(char **map)
{
	t_player	player;
	int			x;
	int			y;

	x = 0;
	player.pos.x = -1;
	while (map[x] && player.pos.x == -1)
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] != '0' && map[x][y] != '1' && map[x][y] != ' ')
			{
				player.pos.x = x;
				player.pos.y = y;
				player.direction = map[x][y];
				break ;
			}
			y++;
		}
		x++;
	}
	return (player);
}

t_vars	init(t_data *data)
{
	t_vars	var;

	var.error = 0;
	var.mlx = mlx_init();
	var.win = create_window(var.mlx);
	var.ea = create_image(var.mlx, data->ea_path);
	var.no = create_image(var.mlx, data->no_path);
	var.so = create_image(var.mlx, data->so_path);
	var.we = create_image(var.mlx, data->we_path);
	if (var.ea.error || var.no.error || var.so.error || var.we.error)
		var.error = 1;
	var.ceiling_color = get_color(data->ceiling_color);
	var.floor_color = get_color(data->floor_color);
	if (var.ceiling_color == -1 || var.floor_color == -1)
		var.error = 1;
	var.player = init_player(data->map);
	var.map = cp_tab_no_player(data->map, var.player.pos);
	if (!var.map)
		var.error = 1;
	*data = destroy_data(*data);
	return (var);
}
