/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarabud <ekarabud@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:54:51 by olyetisk          #+#    #+#             */
/*   Updated: 2024/04/16 20:13:40 by ekarabud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "mlx/mlx.h"
# include "getnextline/get_next_line.h"
# include "printf/ft_printf.h"

typedef struct s_mlx
{
	void	*mlx_win;
	void	*mlx;
	char	**map;
	void	*wall;
	void	*grass;
	void	*bird;
	void	*nest;
	void	*exit;
	void	*worm;
	int		i;
	int		j;
	char	**copy_map;
	int		playerx;
	int		playery;
	int		mapx;
	char	**maps;
	int		axe_count;
	int		exit_count;
	int		player_count;
	int		move;
	int		mapy;
	char	*map_path;
}			t_mlx;
/*
int		get_key(int keycode, t_mlx *solong);
void	take_image_xpm(t_mlx *map);
void	name_ber(char *str);
void	free_map(char **map, char *msg);
void	imagetowin(t_mlx *solong, int x, int y);
char	**getmap(char *av);
int		map_len(char *av);
void	error1(char *str);
void	move_write(char *str);
int		wall(t_mlx *solong);
void	move_write2(char *str);
void	paste_to_image(t_mlx *solong);
void	ft_putnbr(unsigned int a);
void	ft_counter(t_mlx *solong);
int		floodfill(t_mlx *solong);
int		floodfill1(t_mlx *solong);
void	checkmap_chars(char **str);
*/
#endif