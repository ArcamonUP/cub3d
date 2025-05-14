/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 19:39:01 by achu              #+#    #+#             */
/*   Updated: 2025/05/14 12:32:49 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <stdint.h>
# include <stdbool.h>
# include "engine/vector.h"
# include "engine/image.h"
# include "engine/render.h"

typedef enum e_tile
{
	EMPTY = '0',
	WALL = '1',
	NORTH = 'N',
	SOUTH = 'S',
	WEST = 'W',
	EAST = 'E',
	DOOR = 'D',
}	t_tile;

typedef struct s_map
{
	int			height;
	int			width;
	char		**grid;
	bool		**visited;

	t_vec2		player_pos;
	int32_t		max_player;
}	t_map;

#endif