/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarabud <ekarabud@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 22:33:41 by ekarabud          #+#    #+#             */
/*   Updated: 2024/04/18 17:59:20 by ekarabud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
int abort_game(t_mlx *game)
{
    int i;
    if (game -> player != NULL)
        mlx_destroy_image(game -> mlx_init, game -> player);
    if (game -> collectible != NULL)   
        mlx_destroy_image(game -> mlx_init, game -> collectible);
    if (game -> grass != NULL)
        mlx_destroy_image(game -> mlx_init, game -> grass);
    if (game -> wall != NULL)
        mlx_destroy_image(game -> mlx_init, game -> wall);
    if (game -> exit != NULL)
        mlx_destroy_image(game -> mlx_init, game -> exit);
    if (game -> mlx_window != NULL)
        mlx_clear_window(game -> mlx_init, game -> mlx_window);
    i = 0;
    if (game -> map_line != NULL && game -> is_map_allocated == 1)
    {    
        while (i < (game -> map_line_count))
        {
            if (game -> map_line[i] != NULL)
                free(game -> map_line[i]); 
            i++;
        }
        free(game -> map_line);
    }
    exit(EXIT_SUCCESS);
    return (0);
}
