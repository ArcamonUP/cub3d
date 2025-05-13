/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 19:39:01 by achu              #+#    #+#             */
/*   Updated: 2025/05/14 00:56:35 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <stdint.h>
# include <stdbool.h>
# include "engine/vector.h"

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

int		setup_map(t_map *manager, int argc, char **argv);
bool	is_valid_map(t_map *manager);
bool	is_valid_file(int argc, char **argv);
bool	is_valid_pathfinder(t_map *manager);
char	**parse_map(char *file);
void	clean_map(t_map *manager);

#endif