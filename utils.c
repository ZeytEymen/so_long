/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarabud <ekarabud@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:56:57 by ekarabud          #+#    #+#             */
/*   Updated: 2024/04/18 13:43:40 by ekarabud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void    exception(t_mlx *map, char *str)
{
    ft_printf("%s",str);
    abort_game(map);
}

void    exception_with_number(t_mlx *map, char *str, int count)
{
    ft_printf("%s%d",str,count);
    abort_game(map);
}