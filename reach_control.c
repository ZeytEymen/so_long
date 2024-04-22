/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reach_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarabud <ekarabud@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 15:51:43 by ekarabud          #+#    #+#             */
/*   Updated: 2024/04/22 21:49:42 by ekarabud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_cells(t_mlx *map, int y, int x)
{
	if (map->map_line[y][x + 1] == '0' || map->map_line[y][x + 1] == 'C')
	{
		map->map_line[y][x + 1] = 'P';
		fill_cells(map, y, x + 1);
	}
	if (map->map_line[y][x - 1] == '0' || map->map_line[y][x - 1] == 'C')
	{
		map->map_line[y][x - 1] = 'P';
		fill_cells(map, y, x - 1);
	}
	if (map->map_line[y + 1][x] == '0' || map->map_line[y + 1][x] == 'C')
	{
		map->map_line[y + 1][x] = 'P';
		fill_cells(map, y + 1, x);
	}
	if (map->map_line[y - 1][x] == '0' || map->map_line[y - 1][x] == 'C')
	{
		map->map_line[y - 1][x] = 'P';
		fill_cells(map, y - 1, x);
	}
}

int	is_exit_reachable(t_mlx *map)
{
	int	y;
	int	x;

	y = 0;
	while (map->map_line[y] != 0)
	{
		x = 0;
		while (map->map_line[y][x] != '\n')
		{
			if (map->map_line[y][x] == 'E')
				break ;
			x++;
		}
		if (map->map_line[y][x] == 'E')
			break ;
		y++;
	}
	if (map->map_line[y][x + 1] == 'P' || map->map_line[y][x - 1] == 'P' ||
		map->map_line[y + 1][x] == 'P' || map->map_line[y - 1][x] == 'P')
		return (0);
	ft_printf("The player can't access the exit!!\n");
	return (1);
}

int	is_colletible_reachable(t_mlx *map)
{
	int	y;
	int	x;

	y = 0;
	while (map->map_line[y])
	{
		x = 0;
		while (map->map_line[y][x] != 0 && map->map_line[y][x] != '\n')
		{
			if (map->map_line[y][x] == 'C')
			{
				ft_printf("The player can't access the collectibles!!\n");
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	is_reachable(t_mlx *map)
{
	fill_cells(map, map->player_y_loc, map->player_x_loc);
	if (is_exit_reachable(map) || is_colletible_reachable(map))
		return (0);
	return (1);
}
