/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:44:55 by tmarx             #+#    #+#             */
/*   Updated: 2019/10/21 19:29:58 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	char			buffer[BUFFER_SIZE];
	static char		*res[MAX_OPENED];
	int				bytes_read;

	*line = NULL;
	if (fd == -1)
		return (-1);
	bytes_read = 1;
	while (count_bl(res[fd]) <= 0 &&
	(bytes_read = read(fd, buffer, BUFFER_SIZE)) && bytes_read > 0)
		strappend(&(res[fd]), buffer, bytes_read);
	if (bytes_read < 0)
	{
		*line = NULL;
		return (-1);
	}
	if (!bytes_read)
	{
		get_first_line(&(res[fd]), line);
		return (0);
	}
	get_first_line(&(res[fd]), line);
	return (1);
}

void	get_first_line(char **buffer, char **line)
{
	char	*res;
	int		i;

	i = 0;
	if (buffer && *buffer)
	{
		while ((*buffer)[i] && (*buffer)[i] != '\n')
			i++;
	}
	res = ft_calloc(i + 1, sizeof(char));
	if (!res)
		return ;
	if (buffer && *buffer)
	{
		i = 0;
		while ((*buffer)[i] && (*buffer)[i] != '\n')
		{
			res[i] = (*buffer)[i];
			i++;
		}
		if ((*buffer)[i] == '\n')
			i++;
		*buffer = cut_first_chars(*buffer, i);
	}
	free(*line);
	*line = res;
}
