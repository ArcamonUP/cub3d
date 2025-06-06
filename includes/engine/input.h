/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:51:00 by achu              #+#    #+#             */
/*   Updated: 2025/05/13 17:51:01 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# define KEY_W				119
# define KEY_A				97
# define KEY_S				115
# define KEY_D				100

# define KEY_LEFT   		65361
# define KEY_RIGHT  		65363
# define KEY_UP     		65362
# define KEY_DOWN   		65364

# define KEY_SPACE 			32
# define KEY_SHIFT 			65505
# define KEY_ESC			65307
# define KEY_M				109

# define ON_KEYPRESS		2
# define ON_KEYRELEASE		3
# define ON_MOUSE			6
# define ON_DESTROY			17

# include <X11/X.h>
# include <X11/keysym.h>

typedef struct s_system	t_system;

typedef enum e_action
{
	W,
	S,
	A,
	D,
	LEFT,
	RIGHT,
	SHIFT,
	SPACE,
	ESC,
	MAX_ACTION,
}	t_action;

typedef struct s_keybind
{
	int		key;
	int		pressed;
	int		hold;
}	t_keybind;

t_keybind	*init_input(void);
void		update_input(t_keybind *keybind);
int			input_press(int key, t_system *sys);
int			input_release(int key, t_keybind *manager);
int			mouse_move(int x, int y, t_system *sys);

#endif