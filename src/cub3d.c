/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaridon <kbaridon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:08:52 by kbaridon          #+#    #+#             */
/*   Updated: 2025/04/24 14:14:31 by kbaridon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

void	print_data(t_data data)
{
	ft_printf("NO: %s\n", data.no_path);
	ft_printf("SO: %s\n", data.so_path);
	ft_printf("WE: %s\n", data.we_path);
	ft_printf("EA: %s\n", data.ea_path);
	ft_printf("C: %s\n", data.ceiling_color);
	ft_printf("F: %s\n", data.floor_color);
	ft_printf("Map:\n");
	for (int i = 0; data.map[i]; i++)
	{
		ft_printf("%s\n", data.map[i]);
	}
}

int	main(int ac, char **av)
{
	t_data	data;

	data = parsing(ac, av);
	if (!data.map)
		return (1);
	print_data(data);
	data = destroy_data(data);
	return (0);
}
