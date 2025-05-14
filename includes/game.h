 	q/* ************************************************************************** */
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

//end.c
void	end(t_vars var);

//event_listener.c
void	event_listener(t_vars var);

#endif