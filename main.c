/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:36:41 by tmarx             #+#    #+#             */
/*   Updated: 2019/10/17 12:02:37 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int main()
{
	int i = 0;
	char *line = NULL;
	int fd = open("bible.txt", O_RDONLY);
	while (i++ < 5)
	{
		get_next_line(fd, &line);
		printf("%s\n", line);
	}
	close(fd);
}
