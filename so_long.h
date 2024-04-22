/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarabud <ekarabud@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:54:51 by olyetisk          #+#    #+#             */
/*   Updated: 2024/04/22 22:07:59 by ekarabud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf/ft_printf.h"
# include "gnl/get_next_line.h"
# include "mlx/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_mlx
{
	void	*wall;
	void	*grass;
	void	*player;
	void	*exit;
	void	*collectible;
	char	**map_line;
	int		is_map_allocated;
	int		is_image_allocated;
	int		player_x_loc;
	int		player_y_loc;
	int		exit_x_loc;
	int		exit_y_loc;
	int		exit_count;
	int		player_count;
	int		collectible_count;
	int		player_move_count;
	int		map_line_count;
	char	*str_step;
	void	*mlx_init;
	void	*mlx_window;
}			t_mlx;

char		*ft_itoa(int n);
int			line_char_control(char *line);
int			get_key(int keycode, t_mlx *map);
int			free_temp(t_mlx *temp);
void		exception(t_mlx *map, char *str);
void		exception_with_number(t_mlx *map, char *str, int count);
int			abort_game(t_mlx *game);
void		check_file_name(t_mlx *map, char *str);
void		check_arg_count(t_mlx *map, int count);
void		take_image_count(t_mlx *map, int x, int y);
void		image_count_control(t_mlx *map);
int			is_reachable(t_mlx *map);
int			map_line_count(t_mlx *map, char *file_name);
char		**create_map(t_mlx *map, char *file_name, int line_length);
void		take_images(t_mlx *map);
void		put_images(t_mlx *map, void *image, int x, int y);
void		load_images_to_window(t_mlx *map);
void		rectangle_control(t_mlx *map);
void		wall_control(t_mlx *map);
void		new_window(t_mlx *map);
#endif