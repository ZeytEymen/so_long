/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarabud <ekarabud@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:54:51 by olyetisk          #+#    #+#             */
/*   Updated: 2024/04/18 19:31:36 by ekarabud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "mlx/mlx.h"
# include "gnl/get_next_line.h"
# include "ft_printf/ft_printf.h"

typedef struct s_mlx
{
	//textures/images
	void	*wall;			//	1
	void	*grass;			//	0
	void	*player;		//	P
	void	*exit;			//	E
	void	*collectible;	//	C
	//map
	char	**map_line;
	int 	is_map_allocated;
	//locations
	int		player_x_loc;
	int		player_y_loc;
	int		exit_x_loc;
	int		exit_y_loc;
	//counts
	int		exit_count;
	int		player_count;
	int		collectible_count;
	int		player_move_count;
	int		map_line_count;
	//mlx
	void	*mlx_init;
	void	*mlx_window;
	
}			t_mlx;
//	utils
void    exception(t_mlx *map, char *str);
void    exception_with_number(t_mlx *map, char *str, int count);
size_t	ft_strlen(const char *s);
//	checks
void	check_file_name(t_mlx *map, char *str);
void    check_arg_count(t_mlx *map, int count);
void 	take_image_count(t_mlx *map, int x, int y);
void	image_count_control(t_mlx *map);
// map
int		map_line_count(t_mlx *map,char *file_name);
char	**create_map(t_mlx *map,char *file_name, int line_length);
void    take_images(t_mlx *map);
void	put_images(t_mlx *map, void *image, int x, int y);
void    load_images_to_window(t_mlx *map);

int get_key(int keycode,t_mlx *map);
int abort_game(t_mlx *game);
void _test(int number);
void 	rectangle_control(t_mlx *map);
void wall_control(t_mlx *map);
#endif