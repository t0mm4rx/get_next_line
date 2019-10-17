/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:36:41 by tmarx             #+#    #+#             */
/*   Updated: 2019/10/17 23:25:45 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int main()
{
	printf("!%d!\n", BUFFER_SIZE);
	//char *line = NULL;
	int fd = open("bible.txt", O_RDONLY);
	/*while (get_next_line(fd, &line))
	{
		printf("%s\n", i, line);
	}*/
	close(fd);
}
