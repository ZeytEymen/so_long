/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarabud <ekarabud@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 21:55:12 by ekarabud          #+#    #+#             */
/*   Updated: 2024/04/22 22:00:43 by ekarabud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	new_window(t_mlx *map)
{
	map->mlx_window = mlx_new_window(map->mlx_init,
			(ft_strlen(map->map_line[0]) - 1) * 64,
			map->map_line_count * 64,
			"SO_LONG");
	load_images_to_window(map);
}
