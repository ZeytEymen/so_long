/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarabud <ekarabud@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:55:44 by ekarabud          #+#    #+#             */
/*   Updated: 2024/04/16 15:39:43 by ekarabud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strjoin(char *f_str, char *l_str)
{
	char	*new;
	int		location;
	int		i;

	if (!f_str)
	{
		f_str = malloc(sizeof(char) * 1);
		if (!f_str)
			return (NULL);
		f_str[0] = '\0';
	}
	new = malloc(sizeof(char) * (ft_strlen(f_str) + ft_strlen(l_str) + 1));
	if (!new)
		return (NULL);
	location = -1;
	while (f_str[++location] != '\0')
		new[location] = f_str[location];
	i = -1;
	while (l_str[++i] != '\0')
		new[location + i] = l_str[i];
	new[location + i] = '\0';
	free(f_str);
	return (new);
}
