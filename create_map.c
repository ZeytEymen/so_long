/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarabud <ekarabud@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:32:30 by ekarabud          #+#    #+#             */
/*   Updated: 2024/04/17 23:06:42 by ekarabud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	map_line_count(char *file_name)
{
	int		len;
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		exception("Cannot open map map_read");
	len = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		free(line);
		len++;
	}
	if (len <= 0)
		exception("There is no line was found !!");
	close(fd);
	return (len);
}
char	**create_map(char *file_name, int line_length)
{
	int 	len;
	int 	i;
	int		fd;
	char	**map;
	
	len = line_length;
	map = (char **)malloc(sizeof(char *) * (len + 1));
	if(!map)
		exit(EXIT_FAILURE);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		free(map);
		exception("Cannot open map create_map");
	}
	i = 0;
	while (i < len)
	{
		write(1,"test\n",5);
		map[i++] = get_next_line(fd);
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

void    take_images(t_mlx *map)
{
    int w;
    int h;
    
    map -> player = mlx_xpm_file_to_image(map -> mlx_init, "./textures/bird.xpm", &w, &h);
    map -> wall = mlx_xpm_file_to_image(map -> mlx_init, "textures/wall.xpm", &w, &h);
    map -> collectible = mlx_xpm_file_to_image(map -> mlx_init, "textures/worm.xpm", &w, &h);
    map -> grass = mlx_xpm_file_to_image(map -> mlx_init, "textures/grass.xpm", &w, &h);
    map -> exit = mlx_xpm_file_to_image(map -> mlx_init, "textures/nest.xpm", &w, &h);
    if ((!map -> player) || (!map -> wall) || (!map -> collectible) || (!map -> grass) || (!map -> exit))
        exception("Textures could not found !! take_images");
}

void	put_images(t_mlx *map, void *image, int x, int y)
{
	mlx_put_image_to_window(map -> mlx_init, map->mlx_window, image, 64 * x, 64 * y);
}
void    load_images_to_window(t_mlx *map)
{
	int	x;
	int	y;
	
	y = -1;
	take_images(map);
	while (map -> map_line[++y])
	{
		x = -1;
		while (map -> map_line[y][++x])
		{
			if (map -> map_line[y][x] == '0')
				put_images(map, map -> grass, x, y);
			else if(map -> map_line[y][x] == '1')
				put_images(map, map -> wall, x, y);
			else if(map -> map_line[y][x] == 'C')
				put_images(map, map -> collectible, x, y);
			else if(map -> map_line[y][x] == 'E')
				put_images(map, map -> exit, x, y);
			else if(map -> map_line[y][x] == 'P')
			{
				map -> player_x_loc = x;
				map -> player_y_loc = y;
				put_images(map, map -> player, map -> player_x_loc, map -> player_y_loc);
			}
		}
	}
}