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

t_game	*init_game(t_system sys)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->player = init_player();
	game->no = create_image(sys.window.mlx, sys.grid->no_path);
	game->so = create_image(sys.window.mlx, sys.grid->so_path);
	game->ea = create_image(sys.window.mlx, sys.grid->ea_path);
	game->we = create_image(sys.window.mlx, sys.grid->we_path);
	//Pas protege, il faut le faire
	return (game);
}

// void	destroy_game(t_game *game)
// {

// }
