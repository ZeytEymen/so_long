/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarabud <ekarabud@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 22:09:00 by ekarabud          #+#    #+#             */
/*   Updated: 2024/04/17 23:34:55 by ekarabud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void move_up(int x, int y, t_mlx *solong)
{
    y = 5;
    x = 5;
    mlx_clear_window(solong -> mlx_init, solong -> mlx_window);
    ft_printf("move up\n");
}
void move_down()
{
    ft_printf("move down\n");
}
void move_right()
{
    ft_printf("move right\n");
}
void move_left()
{
    ft_printf("move left\n");
}

int get_key(int keycode, t_mlx *solong)
{
    if(keycode == 12)
        move_up(solong -> player_x_loc, --(solong -> player_y_loc), solong);
    else if(keycode == 1)
        move_down();
    else if(keycode == 2)
        move_right();
    else if(keycode == 0)
        move_left();
    else if(keycode == 53)
        abort_game(solong);
	return (0);
}
