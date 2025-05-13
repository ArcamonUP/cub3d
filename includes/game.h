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

# define SOUTH		1
# define NORTH		2
# define EAST		3
# define WEST		4

# include "engine/image.h"
# include "player.h"

typedef struct data
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	char	*ceiling_color;
	char	*floor_color;
	char	**map;
	int		map_is_build;
}	t_data;

typedef struct s_vars
{
	void			*mlx;
	void			*win;
	t_img			no;
	t_img			so;
	t_img			we;
	t_img			ea;
	t_player		player;
	int				ceiling_color;
	int				floor_color;
	char			**map;
	int				error;
}	t_vars;

//parsing.c
t_data	parsing(int ac, char **av);

//parse_utils.c
t_data	set_null(void);
int		is_empty(char *line);
int		ft_dupcheck(char *line, char **str, int *map);
int		ft_tablen(char **tab);

//errors.c
t_data	destroy_data(t_data data);
int		error(char *message);
void	free_tab(char **tab);

//map.c
t_data	parse_map(t_data data, int i, int spawn);

//init_utils.c
char	**cp_tab_no_player(char **tab, t_vec2 pos);
int		get_value(char *str, int *i);

//init.c
t_vars	init(t_data *data);

//end.c
void	end(t_vars var);

//event_listener.c
void	event_listener(t_vars var);

#endif