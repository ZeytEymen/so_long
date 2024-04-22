/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarabud <ekarabud@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 22:33:41 by ekarabud          #+#    #+#             */
/*   Updated: 2024/04/22 22:02:30 by ekarabud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	delete_images(t_mlx *game)
{
	if (game->is_image_allocated == 1)
	{
		if (game->player != NULL)
			mlx_destroy_image(game->mlx_init, game->player);
		if (game->collectible != NULL)
			mlx_destroy_image(game->mlx_init, game->collectible);
		if (game->grass != NULL)
			mlx_destroy_image(game->mlx_init, game->grass);
		if (game->wall != NULL)
			mlx_destroy_image(game->mlx_init, game->wall);
		if (game->exit != NULL)
			mlx_destroy_image(game->mlx_init, game->exit);
		if (game->mlx_window != NULL)
			mlx_clear_window(game->mlx_init, game->mlx_window);
	}
}

int	abort_game(t_mlx *game)
{
	int	i;

	i = 0;
	if (game->map_line != NULL && game->is_map_allocated == 1)
	{
		while (i < (game->map_line_count))
		{
			if (game->map_line[i] != NULL)
				free(game->map_line[i]);
			i++;
		}
		free(game->map_line);
	}
	exit(EXIT_SUCCESS);
	return (0);
}

int	free_temp(t_mlx *temp)
{
	int	i;

	i = 0;
	if (temp->map_line != NULL)
	{
		while (i < (temp->map_line_count))
		{
			if (temp->map_line[i] != NULL)
				free(temp->map_line[i]);
			i++;
		}
		free(temp->map_line);
	}
	return (1);
}
