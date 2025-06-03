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
	char		*no_path;
	char		*so_path;
	char		*we_path;
	char		*ea_path;
	char		*ceiling_color;
	char		*floor_color;
	char		**map;
	int			map_is_build;

	int			height;
	int			width;
	char		**grid;
	bool		**visited;
}	t_map;

//parsing.c
t_map	parsing(int ac, char **av);

//parse_utils.c
t_map	set_null(void);
int		is_empty(char *line);
int		ft_dupcheck(char *line, char **str, int *map);
int		ft_tablen(char **tab);
int		is_all_set(t_map data);

//errors.c
t_map	destroy_data(t_map data);
int		error(char *message);
void	free_tab(char **tab);

//map.c
t_map	parse_map(t_map data, int i, int spawn);

//init_utils.c
char	**cp_tab_no_player(char **tab, t_vec2 pos);
int		get_value(char *str, int *i);

void	free_tab(char **tab);

#endif