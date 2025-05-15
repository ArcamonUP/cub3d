/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:09:59 by kbaridon          #+#    #+#             */
/*   Updated: 2025/05/14 00:37:57 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "engine/image.h"
# include "engine/window.h"
# include "player.h"

typedef struct s_game
{
	t_img			no;
	t_img			so;
	t_img			we;
	t_img			ea;
	int				floor_color;
	int				roof_color;

	t_player		player;
}	t_game;

t_game	*init_game(t_display window);

#endif