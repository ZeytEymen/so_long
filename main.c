/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarabud <ekarabud@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:32:10 by ekarabud          #+#    #+#             */
/*   Updated: 2024/04/18 19:31:48 by ekarabud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	t_mlx solong;
	solong.is_map_allocated = 0;
	check_arg_count(&solong, argc);
	check_file_name(&solong, argv[1]);
	solong.mlx_init = mlx_init();
	solong.map_line =  create_map(&solong, argv[1], map_line_count(&solong, argv[1]));
	image_count_control(&solong);
	rectangle_control(&solong);
	wall_control(&solong);
	solong.mlx_window = mlx_new_window(solong.mlx_init, (ft_strlen(solong.map_line[0]) - 1) * 64, map_line_count(&solong, argv[1]) * 64, "SO_LONG");
	load_images_to_window(&solong);
	mlx_hook(solong.mlx_window, 02, 0L, get_key, &solong); // key eventleri
	mlx_hook(solong.mlx_window, 17, 1L << 2, abort_game, &solong); // çarpı tuşu ile çıkma
	mlx_loop(solong.mlx_init);
}