/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 12:35:58 by tmarx             #+#    #+#             */
/*   Updated: 2019/10/24 16:15:53 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <libc.h>
#include "../get_next_line.h"

void read_file(char const *filename)
{
	int fd;
	int status;
	char *line = NULL;
	int i = 0;

	fd = open(filename, O_RDONLY);
	while ((status = get_next_line(fd, &line)) == 1)
	{
		printf("%d (%d): |%s|\n", ++i, status, line);
		free(line);
	}
	printf("%d (%d): |%s|\n", ++i, status, line);
	free(line);
	close(fd);
}

int main(int argc, char **argv)
{
	read_file(argv[1]);
}
