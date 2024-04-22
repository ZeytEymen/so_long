/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarabud <ekarabud@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:32:30 by ekarabud          #+#    #+#             */
/*   Updated: 2024/04/22 20:25:29 by ekarabud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_line_count(t_mlx *map, char *file_name)
{
	int		len;
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		exception(map, "Cannot open map");
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
	{
		if (line)
			free(line);
		exception(map, "There is no line was found !!");
	}
	close(fd);
	map -> map_line_count = len;
	return (len);
}

char	**create_map(t_mlx *map, char *file_name, int line_length)
{
	int		len;
	int		i;
	int		fd;
	char	**map_line;

	if (map->map_line_count > 128)
		exception(map, "Line count should be < 128");
	len = line_length;
	map_line = (char **)malloc(sizeof(char *) * (len + 1));
	if (!map_line)
		exit(EXIT_FAILURE);
	map -> is_map_allocated = 1;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		exception(map, "Cannot open map");
	i = 0;
	while (i < len)
	{
		map_line[i++] = get_next_line(fd);
		if (ft_strlen(map_line[0]) > 129)
			exception(map, "Line length should be < 128");
	}
	map_line[i] = NULL;
	close(fd);
	return (map_line);
}
