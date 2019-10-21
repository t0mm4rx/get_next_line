/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:44:55 by tmarx             #+#    #+#             */
/*   Updated: 2019/10/21 13:45:05 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	char			buffer[BUFFER_SIZE];
	static t_file	*res_list;
	int				bytes_read;

	if (fd == -1)
	{
		*line = NULL;
		return (-1);
	}
	bytes_read = 1;
	while (count_bl(*fd_to_res(fd, &res_list)) <= 0 &&
	(bytes_read = read(fd, buffer, BUFFER_SIZE)))
		strappend(fd_to_res(fd, &res_list), buffer, bytes_read);
	if (bytes_read < 0)
	{
		*line = NULL;
		return (-1);
	}
	if (!bytes_read)
	{
		get_first_line(fd_to_res(fd, &res_list), line);
		return (0);
	}
	get_first_line(fd_to_res(fd, &res_list), line);
	return (1);
}

void	get_first_line(char **buffer, char **line)
{
	char	*res;
	int		i;

	i = 0;
	while ((*buffer)[i] && (*buffer)[i] != '\n')
		i++;
	res = ft_calloc(i + 1, sizeof(char));
	if (!res)
		return ;
	i = 0;
	while ((*buffer)[i] && (*buffer)[i] != '\n')
	{
		res[i] = (*buffer)[i];
		i++;
	}
	if ((*buffer)[i] == '\n')
		i++;
	*buffer = cut_first_chars(*buffer, i);
	free(*line);
	*line = res;
}

void	add_new_fd(int fd, t_file **list)
{
	t_file *new;
	t_file *ptr;

	new = ft_calloc(1, sizeof(t_file));
	if (!new)
		return ;
	new->next = NULL;
	new->fd = fd;
	new->res = ft_calloc(1, sizeof(char));
	if (!new->res)
		return ;
	if (!(*list))
	{
		*list = new;
		return ;
	}
	ptr = *list;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = new;
}

char	**fd_to_res(int fd, t_file **list)
{
	t_file *ptr;

	if (!(*list))
	{
		add_new_fd(fd, list);
		return (&((*list)->res));
	}
	ptr = *list;
	while (ptr)
	{
		if (ptr->fd == fd)
			return (&(ptr->res));
		ptr = ptr->next;
	}
	add_new_fd(fd, list);
	return (fd_to_res(fd, list));
}
