/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaridon <kbaridon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:09:59 by kbaridon          #+#    #+#             */
/*   Updated: 2025/04/29 13:12:16 by kbaridon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define KEY_ESC 65307

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

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		width;
	int		heigh;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		error;
}	t_img;

typedef struct s_vars
{
	void			*mlx;
	void			*win;
	t_img			no;
	t_img			so;
	t_img			we;
	t_img			ea;
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
char	**cp_tab(char **tab);
int		get_value(char *str, int *i);

//init.c
t_vars	init(t_data *data);

//end.c
void	end(t_vars var);

//event_listener.c
void	event_listener(t_vars var);

#endif