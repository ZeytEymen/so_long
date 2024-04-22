/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarabud <ekarabud@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:56:57 by ekarabud          #+#    #+#             */
/*   Updated: 2024/04/22 19:05:26 by ekarabud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void    exception(t_mlx *map, char *str)
{
    ft_printf("%s\n",str);
    abort_game(map);
}

void    exception_with_number(t_mlx *map, char *str, int count)
{
    ft_printf("%s%d\n",str,count);
    abort_game(map);
}

int line_char_control(char *line)
{
    int i;

    i = -1;
    while (line[++i])
    {
        if (line[i] != '\n')
        {
            if (line[i] != '1')
                return (1);
        }
    }
    return(0);
}

int	ft_nbr(int n)
{
	int	result;

	result = 0;
	if (n == 0)
		result = 1;
	while (n != 0)
	{
		n = n / 10;
		result++;
	}
	return (result);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			len;
	long int	num;

	num = n;
	len = ft_nbr(num);
	if (num < 0)
	{
		num *= -1;
		len++;
	}
	str = (char *)malloc(sizeof(char) * len + 1);
	if (str == 0)
		return (0);
	str[len] = 0;
	while (len--)
	{
		str[len] = (num % 10) + '0';
		num = num / 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}