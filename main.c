/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarabud <ekarabud@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:32:10 by ekarabud          #+#    #+#             */
/*   Updated: 2024/04/22 21:57:08 by ekarabud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_mlx	solong;
	t_mlx	temp;
	int		reachable;

	check_arg_count(&solong, argc);
	check_file_name(&solong, argv[1]);
	solong.mlx_init = mlx_init();
	solong.map_line = create_map(&solong, argv[1], map_line_count(&solong,
				argv[1]));
	image_count_control(&solong);
	rectangle_control(&solong);
	wall_control(&solong);
	new_window(&solong);
	temp.map_line = create_map(&temp, argv[1], map_line_count(&temp, argv[1]));
	if (!temp.map_line)
		abort_game(&solong);
	temp.player_x_loc = solong.player_x_loc;
	temp.player_y_loc = solong.player_y_loc;
	reachable = is_reachable(&temp);
	free_temp(&temp);
	if (!reachable)
		abort_game(&solong);
	mlx_hook(solong.mlx_window, 02, 0L, get_key, &solong);
	mlx_hook(solong.mlx_window, 17, 1L << 2, abort_game, &solong);
	mlx_loop(solong.mlx_init);
}
