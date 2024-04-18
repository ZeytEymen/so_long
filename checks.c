/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarabud <ekarabud@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:25:36 by ekarabud          #+#    #+#             */
/*   Updated: 2024/04/18 20:09:53 by ekarabud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// .ber control
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
// argument count control
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
			{
				map -> player_x_loc = x;
				map -> player_y_loc = y;
				map -> player_count++;
			}
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
		exception_with_number(map, "Error in 'P' character count\nExcepted : 1\nResult :",map -> player_count);
	if (map -> collectible_count == 0)
		exception_with_number(map, "Error in 'C' character count\nExcepted : count > 0\nResult :",map -> collectible_count);
	if (map -> exit_count != 1)
		exception_with_number(map, "Error in 'E' character count\nExcepted : 1\nResult :",map -> exit_count);
}

void rectangle_control(t_mlx *map)
{
	int line_length;
	int i;
	
	i = 0;
	line_length = ft_strlen(map -> map_line[0]);
	//ft_printf("%d",map -> map_line_count);
	// while (i < map -> map_line_count)
	// {
	// 	if (line_length != (int)ft_strlen(map -> map_line[i]))
	// 		exception(map, "The line lengths of the map are not equal !!");
	// 	i++;
	// }
}

void wall_control(t_mlx *map)
{
	(void)map;
	//int line = map -> map_line_count - 1;
	// if (ft_strchr(map -> map_line[0],'1'))
	// {
	// 	_test(1);
	// }
	// else
	// 	_test(2);
}