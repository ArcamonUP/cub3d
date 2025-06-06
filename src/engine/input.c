/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 00:51:53 by achu              #+#    #+#             */
/*   Updated: 2025/05/14 00:51:59 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/input.h"
#include "system.h"
#include "player.h"

// Initialize all input
t_keybind	*init_input(void)
{
	static t_keybind	button[MAX_ACTION];
	int					i;

	i = 0;
	while (i < MAX_ACTION)
	{
		button[i].key = 0;
		button[i].hold = 0;
		button[i].pressed = 0;
		i++;
	}
	button[W].key = KEY_W;
	button[S].key = KEY_S;
	button[A].key = KEY_A;
	button[D].key = KEY_D;
	button[LEFT].key = KEY_LEFT;
	button[RIGHT].key = KEY_RIGHT;
	button[SPACE].key = KEY_SPACE;
	button[SHIFT].key = KEY_SHIFT;
	button[ESC].key = KEY_ESC;
	return (button);
}

// Update all pressed input to reset after 1 frame
void	update_input(t_keybind *keybind)
{
	int		i;

	i = 0;
	while (i < MAX_ACTION)
	{
		keybind[i].pressed = 0;
		i++;
	}
}

// mlx_hook for input key pressed
int	input_press(int key, t_system *sys)
{
	int			i;
	t_keybind	*keybind;

	keybind = sys->input;
	i = 0;
	if (key == KEY_ESC)
		destroy_system(sys);
	if (key == KEY_M)
	{
		if (sys->mouse)
			mlx_mouse_show_no_leak(sys);
		else
			mlx_mouse_hide_no_leak(sys);
	}
	while (i < MAX_ACTION)
	{
		if (keybind[i].key == key)
		{
			if (keybind[i].hold == 0)
				keybind[i].pressed = 1;
			keybind[i].hold = 1;
		}
		i++;
	}
	return (0);
}

// mlx_hook for input key released
int	input_release(int key, t_keybind *keybind)
{
	int	i;

	i = 0;
	while (i < MAX_ACTION)
	{
		if (keybind[i].key == key)
			keybind[i].hold = 0;
		i++;
	}
	return (0);
}

int	mouse_move(int x, int y, t_system *sys)
{
	int	dx;

	if (sys->mouse == 0)
		return (0);
	(void)y;
	dx = x - sys->last_x;
	sys->move_x = dx;
	sys->last_x = x;
	return (0);
}
