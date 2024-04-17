/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarabud <ekarabud@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 22:33:41 by ekarabud          #+#    #+#             */
/*   Updated: 2024/04/17 22:54:34 by ekarabud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
int abort_game(t_mlx *game)
{
    int i;
    
    mlx_destroy_image(game -> mlx_init, game -> player);
    mlx_destroy_image(game -> mlx_init, game -> collectible);
    mlx_destroy_image(game -> mlx_init, game -> grass);
    mlx_destroy_image(game -> mlx_init, game -> wall);
    mlx_destroy_image(game -> mlx_init, game -> exit);
    mlx_clear_window(game -> mlx_init, game -> mlx_window);
    i = 0;
    while (i < (game -> map_line_count))
    {
        free(game -> map_line[i]);
        i++;
    }
    free(game -> map_line);
    exit(0);
    return (0);
}