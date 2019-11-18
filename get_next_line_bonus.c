/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 12:29:24 by tmarx             #+#    #+#             */
/*   Updated: 2019/11/18 12:29:30 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int				get_next_line(int fd, char **line)
{
	static char	*buffers[MAX_OPEN];
	char		buffer[BUFFER_SIZE + 1];
	int			bytes_read;

	if (BUFFER_SIZE < 0 || fd <= -1
			|| (!buffers[fd] && !(buffers[fd] = ft_calloc(1, sizeof(char)))))
		return (-1);
	bytes_read = 42;
	while (!count_bl(buffers[fd])
			&& (bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
		ft_strjoin(&buffers[fd], buffer, bytes_read);
	if (bytes_read >= 0)
		*line = first_line(buffers[fd]);
	if (bytes_read <= 0)
		free(buffers[fd]);
	if (bytes_read == 0)
		return (0);
	else if (bytes_read < 0)
	{
		*line = NULL;
		return (-1);
	}
	cut(&buffers[fd]);
	return (1);
}

unsigned int	count_bl(const char *str)
{
	unsigned int i;
	unsigned int res;

	i = 0;
	res = 0;
	while (str[i])
	{
		if (str[i++] == '\n')
			res++;
	}
	return (res);
}
