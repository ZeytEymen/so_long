/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarabud <ekarabud@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 20:18:10 by ekarabud          #+#    #+#             */
/*   Updated: 2024/04/16 20:18:11 by ekarabud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	name_ber(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (i <= 3)
	{
		error1 ("Name Error");
	}
	if (str[i] != 'r' || str[i - 1] != 'e' || str[i - 2] != 'b'
		|| str[i - 3] != '.')
	{
		error1 (".Ber Incorrect");
	}
}
