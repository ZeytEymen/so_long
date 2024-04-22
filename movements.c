/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarabud <ekarabud@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 22:09:00 by ekarabud          #+#    #+#             */
/*   Updated: 2024/04/22 22:06:07 by ekarabud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_move(t_mlx *map, int x, int y)
{
	if (map->map_line[y][x] != '1' && map->map_line[y][x] != 'E')
	{
		ft_printf("Step Count: %d\n", ++map->player_move_count);
		if (map->map_line[y][x] == 'C')
		{
			ft_printf("You found the bait\n");
			map->collectible_count--;
		}
		map->map_line[map->player_y_loc][map->player_x_loc] = '0';
		map->map_line[y][x] = 'P';
		map->player_y_loc = y;
		map->player_x_loc = x;
	}
	else if (map->map_line[y][x] == 'E' && map->collectible_count == 0)
	{
		ft_printf("Step Count : %d\n", ++map->player_move_count);
		abort_game(map);
	}
}

int	get_key(int keycode, t_mlx *map)
{
	int		x;
	int		y;
	char	*move;

	x = map->player_x_loc;
	y = map->player_y_loc;
	if (keycode == 13)
		y--;
	else if (keycode == 1)
		y++;
	else if (keycode == 2)
		x++;
	else if (keycode == 0)
		x--;
	else if (keycode == 53)
		abort_game(map);
	else
		return (0);
	mlx_clear_window(map->mlx_init, map->mlx_window);
	map_move(map, x, y);
	load_images_to_window(map);
	move = ft_itoa(map->player_move_count);
	mlx_string_put(map->mlx_init, map->mlx_window, 15, 15, 16777215, move);
	free(move);
	return (0);
}
