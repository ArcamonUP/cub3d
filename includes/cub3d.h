/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaridon <kbaridon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:09:59 by kbaridon          #+#    #+#             */
/*   Updated: 2025/04/24 14:49:07 by kbaridon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

typedef struct data
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	char	*ceiling_color;
	char	*floor_color;
	char	**map;
}	t_data;

//parsing.c
t_data	parsing(int ac, char **av);

//parse_utils.c
t_data	set_null(void);
int		is_empty(char *line);
int		ft_strdupcheck(char *line, char **str);
int		ft_tablen(char **tab);

//errors.c
t_data	destroy_data(t_data data);
int		error(char *message);
void	free_tab(char **tab);

//map.c
t_data	parse_map(t_data data, int i, int spawn);

#endif