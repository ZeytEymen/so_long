/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarabud <ekarabud@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:18:49 by ekarabud          #+#    #+#             */
/*   Updated: 2024/04/22 19:03:15 by ekarabud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    take_images(t_mlx *map)
{
    int w;
    int h;
	
    map -> player = mlx_xpm_file_to_image(map -> mlx_init, "./textures/bird.xpm", &w, &h);
    map -> wall = mlx_xpm_file_to_image(map -> mlx_init, "./textures/wall.xpm", &w, &h);
    map -> collectible = mlx_xpm_file_to_image(map -> mlx_init, "./textures/worm.xpm", &w, &h);
    map -> grass = mlx_xpm_file_to_image(map -> mlx_init, "./textures/grass.xpm", &w, &h);
    map -> exit = mlx_xpm_file_to_image(map -> mlx_init, "./textures/nest.xpm", &w, &h);
    if ((!map -> player) || (!map -> wall) || (!map -> collectible) || (!map -> grass) || (!map -> exit))
        exception(map,"Textures could not found !!");
}

void	put_images(t_mlx *map, void *image, int x, int y)
{
	mlx_put_image_to_window(map -> mlx_init, map->mlx_window, image, x * 64, y * 64);
}

void    load_images(t_mlx *map, int x, int y)
{
    if (map -> map_line[y][x] == '0')
        put_images(map, map -> grass, x, y);
    else if(map -> map_line[y][x] == '1')
        put_images(map, map -> wall,  x,y);
    else if(map -> map_line[y][x] == 'C')
        put_images(map, map -> collectible,  x,y);
    else if(map -> map_line[y][x] == 'E')
    {
        map -> exit_x_loc = x;
        map -> exit_y_loc = y;
        put_images(map, map -> exit,  x,y);
    }
    else if(map -> map_line[y][x] == 'P')
    {
        put_images(map, map -> player, x, y);
        map -> player_x_loc = x;
        map -> player_y_loc = y;
    }
    else if (map -> map_line[y][x] != '\n' && map -> map_line[y][x] != '\0')
    {
        ft_printf("Unexpected character on map : %c\nExcepted characters : [0,1,C,E,P]",map -> map_line[y][x]);
        abort_game(map);
    }
}
void    load_images_to_window(t_mlx *map)
{
	int	x;
	int	y;

	y = -1;
    map -> map_y = 0;
	take_images(map);
	while (map -> map_line[++y])
	{
		x = -1;
        map -> map_x = 0;
		while (map -> map_line[y][++x])
		{
			load_images(map,x,y);
		}
	}
    map -> is_image_allocated = 1;
}
