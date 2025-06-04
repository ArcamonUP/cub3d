/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 22:42:41 by achu              #+#    #+#             */
/*   Updated: 2025/05/14 22:48:24 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYSTEM_H
# define SYSTEM_H

# include "engine/window.h"
# include "engine/image.h"
# include "engine/input.h"
# include "game.h"
# include "map.h"

typedef struct s_system
{
	t_display	window;
	t_image		buffer;
	t_keybind	*input;
	int			move_x;
	int			last_x;
	t_game		*game;
	t_map		*grid;
	double		last;
	double		delta;
	int			mouse;
}	t_system;

t_system	*init_system(void);
int32_t		destroy_system(t_system	*sys);
double		get_frame(void);

#endif