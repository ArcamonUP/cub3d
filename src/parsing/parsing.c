/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:16:11 by kbaridon          #+#    #+#             */
/*   Updated: 2025/05/14 00:34:29 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include "map.h"
#include "libft.h"

char	**get_cpy(char **map, char *line)
{
	int		i;
	char	**temp;

	i = 0;
	while (map[i])
		i++;
	temp = ft_calloc(i + 2, sizeof(char *));
	if (!temp)
		return (NULL);
	i = 0;
	while (map[i])
	{
		temp[i] = map[i];
		i++;
	}
	temp[i] = line;
	temp[i + 1] = NULL;
	free(map);
	return (temp);
}

int	update_map(char *line, char ***map, t_map *data)
{
	char	**temp;
	char	*clean_line;

	if (data->map_is_build == 2 || !check_is_end(data))
		return (1);
	data->map_is_build = 1;
	if (ft_strchr(line, '\n'))
		clean_line = ft_substr(line, 0, ft_strlen(line) - 1);
	else
		clean_line = ft_strdup(line);
	if (!clean_line)
		return (1);
	if (!(*map))
	{
		*map = ft_calloc(2, sizeof(char *));
		if (!*map)
			return (free(clean_line), 1);
		(*map)[0] = clean_line;
		return (0);
	}
	temp = get_cpy(*map, clean_line);
	if (!temp)
		return (free(clean_line), 1);
	*map = temp;
	return (0);
}

int	dispatch_init(t_map *data, char *line)
{
	int	i;
	int	error;

	if (is_empty(line))
		return (0);
	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (ft_strncmp(line + i, "NO", 2) == 0)
		error = ft_dupcheck(line + i + 2, &data->no_path, &data->map_is_build);
	else if (ft_strncmp(line + i, "EA", 2) == 0)
		error = ft_dupcheck(line + i + 2, &data->ea_path, &data->map_is_build);
	else if (ft_strncmp(line + i, "WE", 2) == 0)
		error = ft_dupcheck(line + i + 2, &data->we_path, &data->map_is_build);
	else if (ft_strncmp(line + i, "SO", 2) == 0)
		error = ft_dupcheck(line + i + 2, &data->so_path, &data->map_is_build);
	else if (ft_strncmp(line + i, "F", 1) == 0)
		error = ft_dupcheck(line + i + 1, &data->floor_color, \
			&data->map_is_build);
	else if (ft_strncmp(line + i, "C", 1) == 0)
		error = ft_dupcheck(line + i + 1, &data->ceiling_color, \
			&data->map_is_build);
	else
		error = update_map(line, &data->map, data);
	return (error);
}

t_map	init_data(t_map data, int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (dispatch_init(&data, line))
		{
			(free(line), get_next_line(-1));
			data = destroy_data(data);
			break ;
		}
		free(line);
		line = get_next_line(fd);
	}
	return (data);
}

t_map	parsing(int ac, char **av)
{
	int		i;
	int		fd;
	t_map	data;

	data = set_null();
	if (ac != 2)
		return (error("Error\nInvalid format (./cub3d <map>)"), data);
	i = ft_strlen(av[1]) - 4;
	if (i < 0 || ft_strncmp(av[1] + i, ".cub", 4) != 0)
		return (error("Error\nThe file must end with .cub"), data);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (error("Error\nCannot open file."), data);
	data = init_data(data, fd);
	close(fd);
	if (!data.map)
		return (error("Error\nInit failed."), data);
	if (is_not_good(data))
		return (destroy_data(data));
	return (parse_map(data, -1, 0));
}
