/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 22:50:40 by achu              #+#    #+#             */
/*   Updated: 2025/05/14 22:55:25 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "system.h"

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
	image.screen.mlx = NULL;
	if (!image.addr)
		image.error = 1;
	image.screen.mlx = mlx;
	return (image);
}

t_game	*init_game(t_system sys)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->player = init_player(sys);
	game->no = create_image(sys.window.mlx, sys.grid->no_path);
	game->so = create_image(sys.window.mlx, sys.grid->so_path);
	game->ea = create_image(sys.window.mlx, sys.grid->ea_path);
	game->we = create_image(sys.window.mlx, sys.grid->we_path);
	//Pas protege, il faut le faire
	return (game);
}
