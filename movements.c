/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarabud <ekarabud@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 22:09:00 by ekarabud          #+#    #+#             */
/*   Updated: 2024/04/18 14:07:39 by ekarabud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void move_up()
{
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

int get_key(int keycode, t_mlx *map)
{
    if(keycode == 13)
        move_up();
    else if(keycode == 1)
        move_down();
    else if(keycode == 2)
        move_right();
    else if(keycode == 0)
        move_left();
    else if(keycode == 53)
        abort_game(map);
	return (0);
}
