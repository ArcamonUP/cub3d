/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:50:18 by achu              #+#    #+#             */
/*   Updated: 2025/05/14 12:24:15 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "engine/image.h"
# include "engine/vector.h"
# include "system.h"

# define WHITE		    0xFFFFFFFF
# define BLACK		    0x00000000
# define RED		    0xFFFF0000
# define GREEN		    0xFF00
# define BLUE		    0x0000FF
# define YELLOW		    0xFFFF00
# define CYAN		    0x00FFFF
# define MAGENTA	    0xFF00FF

void	render(t_system *sys);

void	draw_bg(t_image *game);
void	draw_square(t_image *image, t_rect rect, unsigned int color);
void	draw_rect(t_image *image, t_rect rect, unsigned int color);
void	draw_circle(t_image *image, t_vec2 start, int radius);

#endif