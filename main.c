/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:36:41 by tmarx             #+#    #+#             */
/*   Updated: 2019/10/18 10:59:25 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int main()
{
	printf("BUFFER_SIZE=%d\n", BUFFER_SIZE);
	char *line = NULL;
	int fd = open("test.txt", O_RDONLY);
	int status;
	while ((status = get_next_line(fd, &line)) == 1)
		printf("%s\n", line);
	close(fd);
}
