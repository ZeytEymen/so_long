/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarabud <ekarabud@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 20:18:09 by ekarabud          #+#    #+#             */
/*   Updated: 2024/04/22 21:58:25 by ekarabud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	rectangle_control(t_mlx *map)
{
	int	line_length;
	int	i;

	i = 0;
	line_length = (int)ft_strlen(map->map_line[0]);
	while (i <= map->map_line_count - 1 && map->map_line[i])
	{
		if (i == (map->map_line_count - 1)
			&& line_length != ((int)ft_strlen(map->map_line[i]) - 1))
			line_length--;
		if (line_length != (int)ft_strlen(map->map_line[i]))
			exception(map, "Rectangle Error");
		i++;
	}
}

void	wall_control(t_mlx *map)
{
	int	length;
	int	i;

	i = 0;
	length = (int)ft_strlen(map->map_line[1]) - 2;
	if (line_char_control(map->map_line[0])
		|| line_char_control(map->map_line[map->map_line_count - 1]))
		exception(map, "Wall Error !!");
	while (++i <= map->map_line_count - 2)
	{
		if (map->map_line[i][0] != '1' || map->map_line[i][length] != '1')
			exception(map, "Middle Wall Error");
	}
}
