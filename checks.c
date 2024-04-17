/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarabud <ekarabud@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:25:36 by ekarabud          #+#    #+#             */
/*   Updated: 2024/04/17 13:46:51 by ekarabud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_file_name(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (i <= 3)
		exception ("There is no file");
	if (str[i] != 'r' || str[i - 1] != 'e' || str[i - 2] != 'b'
		|| str[i - 3] != '.')
		exception ("File extension is incorrect Are you sure the extension is .ber");
}

void    check_arg_count(int count)
{
    if(count != 2)
		exception("Number of arguments is incorrect, only 2 arguments are accepted");
}