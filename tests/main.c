/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 12:35:58 by tmarx             #+#    #+#             */
/*   Updated: 2019/10/24 13:20:16 by tmarx            ###   ########.fr       */
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

	fd = open(filename, O_RDONLY);
	while ((status = get_next_line(fd, &line)) == 1)
		printf("%d: %s\n", status, line);
	printf("%d: %s\n", status, line);
	close(fd);
}

int main()
{
	//read_file("normal");
	char *str = ft_calloc(1, sizeof(char));
	//memcpy(str, "Okk", 3);
	printf("%s\n", first_line("Salut!\nComment ca va ?\n"));
	printf("%s\n", first_line("Ok"));
	printf("Before cut: |%s|\n", str);
	cut(&str);
	printf("After cut: |%s|\n", str);
}
