/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:59:26 by tmarx             #+#    #+#             */
/*   Updated: 2019/10/17 12:52:50 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static char	buffer[2];
	char		*res;

	(void)line;
	(void)fd;
	res = ft_calloc(1, sizeof(char));
	if (!res)
		return (-1);
	while (count_bl(buffer) <= 0)
	{
		read(fd, buffer, 2);
		res = strappend(res, buffer, 2);
		printf("%s\n", res);
	}
	//printf("%s\n", res);
	return (0);
}
