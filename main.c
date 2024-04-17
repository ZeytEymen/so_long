/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarabud <ekarabud@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:32:10 by ekarabud          #+#    #+#             */
/*   Updated: 2024/04/17 22:56:29 by ekarabud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	t_mlx solong;
	
	check_arg_count(argc);
	check_file_name(argv[1]);
	solong.mlx_init = mlx_init();
	solong.map_line =  create_map(argv[1],map_line_count(argv[1]));
	solong.mlx_window = mlx_new_window(solong.mlx_init, (ft_strlen(solong.map_line[0]) - 1) * 64, map_line_count(argv[1]) * 64, "solong");
	load_images_to_window(&solong);
	mlx_hook(solong.mlx_window, 02, 0L, get_key, &solong); // key eventleri
	mlx_hook(solong.mlx_window, 17, 1L << 2, abort_game, &solong); // çarpı tuşu ile çıkma
	mlx_loop(solong.mlx_init);
}