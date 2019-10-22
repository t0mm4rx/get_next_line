#include "../get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int fd = open("bible.txt", O_RDONLY);
	int status = 0;
	char *line = NULL;
	while ((get_next_line(fd, &line)) == 1)
		printf("%s\n", line);

}
