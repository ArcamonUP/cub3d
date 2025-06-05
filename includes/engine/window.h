/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:47:54 by achu              #+#    #+#             */
/*   Updated: 2025/05/13 19:22:59 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# define WINDOW_WIDTH		1280
# define WINDOW_HEIGHT		720
# define WINDOW_TITLE		"cub3d"

# include "mlx.h"

typedef struct s_display
{
	void	*mlx;
	void	*win;
	int		height;
	int		width;
}	t_display;

t_display	*init_window(void);
void		destroy_window(t_display *window);

#endif