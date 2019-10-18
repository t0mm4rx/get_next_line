/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:59:26 by tmarx             #+#    #+#             */
/*   Updated: 2019/10/19 01:10:35 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	char		buffer[BUFFER_SIZE];
	static char	*res;
	int			bytes_read;

	if (!res)
		res = ft_calloc(1, sizeof(char));
	if (!res || fd == -1)
		return (-1);
	while (count_bl(res) <= 0 && (bytes_read = read(fd, buffer, BUFFER_SIZE)))
		res = strappend(res, buffer, bytes_read);
	if (bytes_read < 0)
		return (-1);
	if (!bytes_read)
	{
		*line = res;
		return (0);
	}
	get_first_line(&res, line);
	return (1);
}

char	*get_first_line(char **buffer, char **line)
{
	char	*res;
	int		i;

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
	*line = res;
	return (res);
}
