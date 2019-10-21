#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main()
{
	int i = 0;
	int j;

	while (1)
	{
		i++;
		if ((j = open("bible.txt", O_RDONLY)) == -1)
		{
			perror("ERROR");
			exit(0);
		}
		printf("%d\n", i);
		printf("fd: %d\n", j);
	}
}
