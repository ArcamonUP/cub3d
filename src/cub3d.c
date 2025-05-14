/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:08:52 by kbaridon          #+#    #+#             */
/*   Updated: 2025/05/14 12:34:12 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "libft.h"

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
}

void	print_vars(t_vars var)
{
	if (!var.no.error)
		ft_printf("NO: yes\n");
	else
		ft_printf("NO: no\n");
	if (!var.so.error)
		ft_printf("SO: yes\n");
	else
		ft_printf("SO: no\n");
	if (!var.we.error)
		ft_printf("WE: yes\n");
	else
		ft_printf("WE: no\n");
	if (!var.ea.error)
		ft_printf("EA: yes\n");
	else
		ft_printf("EA: no\n");
	if (var.ceiling_color)
		ft_printf("C: %x\n", var.ceiling_color);
	else
		ft_printf("C: no\n");
	if (var.floor_color)
		ft_printf("F: %x\n", var.floor_color);
	else
		ft_printf("F: no\n");
	if (var.map)
		ft_printf("Map: yes\n");
	else
		ft_printf("Map: no\n");
	print_map(var.map);
}

static int32_t	update()
{
	
}

static int32_t	start()
{
	
}

int	main(int ac, char **av)
{
	t_data	data;
	t_vars	vars;

	data = parsing(ac, av);
	if (!data.map)
		return (1);
	vars = init(&data);
	if (vars.error)
		end(vars);
	print_vars(vars);
	event_listener(vars);
	return (0);
}
