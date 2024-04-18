/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarabud <ekarabud@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 22:33:41 by ekarabud          #+#    #+#             */
/*   Updated: 2024/04/18 13:58:59 by ekarabud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
int abort_game(t_mlx *game)
{
    int i;
    if (game -> player)
        mlx_destroy_image(game -> mlx_init, game -> player);
    if (game -> collectible)   
        mlx_destroy_image(game -> mlx_init, game -> collectible);
    if (game -> grass)
        mlx_destroy_image(game -> mlx_init, game -> grass);
    if (game -> wall)
        mlx_destroy_image(game -> mlx_init, game -> wall);
    if (game -> exit)
        mlx_destroy_image(game -> mlx_init, game -> exit);
    if (game -> mlx_window)
        mlx_clear_window(game -> mlx_init, game -> mlx_window);
    i = 0;
    if (game -> map_line)
    {
       while (i < (game -> map_line_count))
        {
            free(game -> map_line[i]);
            i++;
        }
        free(game -> map_line);
    }
    exit(EXIT_SUCCESS);
    return (0);
}