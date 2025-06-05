/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hide_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaridon <kbaridon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 12:41:16 by kbaridon          #+#    #+#             */
/*   Updated: 2025/06/04 12:59:29 by kbaridon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/extensions/Xfixes.h>
#include "mlx_int.h"
#include "system.h"

void	mlx_mouse_hide_no_leak(t_system *sys)
{
	t_xvar		*xvar;
	t_win_list	*xwin;

	if (sys->window.mlx == NULL || sys->window.win == NULL)
		return ;
	xvar = (t_xvar *)sys->window.mlx;
	xwin = (t_win_list *)sys->window.win;
	sys->mouse = 1;
	XFixesHideCursor(xvar->display, xwin->window);
}

void	mlx_mouse_show_no_leak(t_system *sys)
{
	t_xvar		*xvar;
	t_win_list	*xwin;

	if (sys->window.mlx == NULL || sys->window.win == NULL)
		return ;
	xvar = (t_xvar *)sys->window.mlx;
	xwin = (t_win_list *)sys->window.win;
	sys->mouse = 0;
	XFixesShowCursor(xvar->display, xwin->window);
}
