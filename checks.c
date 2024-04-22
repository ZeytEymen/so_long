/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarabud <ekarabud@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:25:36 by ekarabud          #+#    #+#             */
/*   Updated: 2024/04/22 19:44:44 by ekarabud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_file_name(t_mlx *map, char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (i <= 3)
		exception (map, "There is no file");
	if (str[i] != 'r' || str[i - 1] != 'e' || str[i - 2] != 'b'
		|| str[i - 3] != '.')
		exception (map, "File extension is incorrect Are you sure the extension is .ber");
}

void    check_arg_count(t_mlx *map, int count)
{
    if(count != 2)
		exception(map, "Number of arguments is incorrect, only 2 arguments are accepted");
}

void take_image_count(t_mlx *map, int x, int y)
{
	map -> player_count = 0;	
	map -> collectible_count = 0;	
	map -> exit_count = 0;
	y = -1;
	while (map -> map_line[++y])
	{
		x = -1;
		while (map -> map_line[y][++x])
		{
			if (map -> map_line[y][x] == 'P')
				map -> player_count++;
			else if(map -> map_line[y][x] == 'C')
				map -> collectible_count++;
			else if(map -> map_line[y][x] == 'E')
				map -> exit_count++;
		}
	}
}
void image_count_control(t_mlx *map)
{
	take_image_count(map, 0, 0);
	if (map -> player_count != 1)
		exception_with_number(map, "Error in 'P' character count\nExcepted : 1\nResult : ",map -> player_count);
	if (map -> collectible_count == 0)
		exception_with_number(map, "Error in 'C' character count\nExcepted : count > 0\nResult : ",map -> collectible_count);
	if (map -> exit_count != 1)
		exception_with_number(map, "Error in 'E' character count\nExcepted : 1\nResult : ",map -> exit_count);
}

void rectangle_control(t_mlx *map)
{
	int line_length;
	int i;
	
	i = 0;
	line_length = (int)ft_strlen(map -> map_line[0]);
	while (i <= map -> map_line_count - 1 && map -> map_line[i])
	{
		if(i == (map -> map_line_count - 1) && line_length != ((int)ft_strlen(map -> map_line[i]) - 1))
			line_length--;
		if (line_length != (int)ft_strlen(map -> map_line[i]))
			exception(map, "Line lengths must be the same length and there must be no blank lines");
		i++;
	}
}

void wall_control(t_mlx *map)
{
	int length;
	int i;
	
	i = 0;
	length = (int)ft_strlen(map -> map_line[1]) - 2;
	if (line_char_control(map -> map_line[0]) || line_char_control(map -> map_line[map -> map_line_count - 1]))
		exception(map,"Wall Error !!");
	while (++i <= map -> map_line_count - 2)
	{
		if (map -> map_line[i][0] != '1' || map -> map_line[i][length] != '1')
			exception(map,"Middle Wall Error");
	}
}