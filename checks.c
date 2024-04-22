/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarabud <ekarabud@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:25:36 by ekarabud          #+#    #+#             */
/*   Updated: 2024/04/22 21:19:15 by ekarabud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_file_name(t_mlx *map, char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (i <= 3)
		exception(map, "There is no file");
	if (str[i] != 'r' || str[i - 1] != 'e' || str[i - 2] != 'b'
		|| str[i - 3] != '.')
		exception(map, ".ber Error!");
}

void	check_arg_count(t_mlx *map, int count)
{
	map->is_image_allocated = 0;
	map->str_step = 0;
	map->player_move_count = 0;
	map->is_map_allocated = 0;
	if (count != 2)
		exception(map, "Only 2 argument !!");
}

void	take_image_count(t_mlx *map, int x, int y)
{
	map->player_count = 0;
	map->collectible_count = 0;
	map->exit_count = 0;
	y = -1;
	while (map->map_line[++y])
	{
		x = -1;
		while (map->map_line[y][++x])
		{
			if (map->map_line[y][x] == 'P')
				map->player_count++;
			else if (map->map_line[y][x] == 'C')
				map->collectible_count++;
			else if (map->map_line[y][x] == 'E')
				map->exit_count++;
		}
	}
}

void	image_count_control(t_mlx *map)
{
	take_image_count(map, 0, 0);
	if (map->player_count != 1)
		exception_with_number(map, "'P' Error\nE : 1\nR : ",
			map->player_count);
	if (map->collectible_count == 0)
		exception_with_number(map, "'C' Error\nE : > 0\nR : ",
			map->collectible_count);
	if (map->exit_count != 1)
		exception_with_number(map, "'E' Error\nE : 1\nR : ",
			map->exit_count);
}
