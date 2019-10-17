/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:59:26 by tmarx             #+#    #+#             */
/*   Updated: 2019/10/17 23:25:34 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//#define BUFFER_SIZE 16668

int	get_next_line(int fd, char **line)
{
	char		buffer[BUFFER_SIZE];
	static char	*res;

	if (!res)
		res = ft_calloc(1, sizeof(char));
	if (!res)
		return (-1);
	while (count_bl(res) <= 0)
	{
		read(fd, buffer, BUFFER_SIZE);
		res = strappend(res, buffer, BUFFER_SIZE);
	}
	*line = get_first_line(&res);
	return (1);
}

char	*get_first_line(char **buffer)
{
	char	*res;
	int 	i;

	i = 0;
	while ((*buffer)[i] != '\n')
		i++;
	res = ft_calloc(i + 1, sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while ((*buffer)[i] != '\n')
	{
		res[i] = (*buffer)[i];
		i++;
	}
	*buffer = cut_first_chars(*buffer, i + 1);
	return (res);
}
