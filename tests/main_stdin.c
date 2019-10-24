/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 12:35:58 by tmarx             #+#    #+#             */
/*   Updated: 2019/10/24 18:46:14 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <libc.h>
#include "../get_next_line.h"

void read_file()
{
	int status;
	char *line = NULL;

	while ((status = get_next_line(0, &line)) == 1)
	{
		printf("%d: |%s|\n", status, line);
		free(line);
	}
	printf("%d: |%s|\n", status, line);
	free(line);
}

int main(int argc, char **argv)
{
	read_file();
}
