/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:36:41 by tmarx             #+#    #+#             */
/*   Updated: 2019/10/21 10:31:21 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line_bonus.h"

int main()
{
	printf("BUFFER_SIZE=%d\n", BUFFER_SIZE);
	char *line1 = NULL;
	char *line2 = NULL;
	int fd = open("test", O_RDONLY);
	int fd2 = open("test2", O_RDONLY);
	int i = 0;
	while (i++ < 5)
	{
		get_next_line(fd, &line1);
		get_next_line(fd2, &line2);
		printf("%s:%s\n", line1, line2);
	}
	close(fd);
	close(fd2);
}
