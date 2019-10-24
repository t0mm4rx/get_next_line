#include <stdio.h>
#include "../get_next_line_bonus.h"
#include <stdlib.h>

void cat_file(char const *file)
{
	int fd = open(file, O_RDONLY);
	printf("Reading file with fd \033[0;32m%d\033[0m with a buffer of \033[0;32m%d\033[0m bytes\n", fd, BUFFER_SIZE);
	char *line = NULL;
	int status;
	int line_count = 0;
	while ((status = get_next_line(fd, &line)) == 1)
		printf("(status: %d) %d: |%s|\n", status, line_count++, line);
	//printf("(status: %d): |%s|\n", status, line);
	close(fd);
}

void cat_files(char **files, int size)
{
	int i = 0;
	int j = 0;
	int fd[size];
	char *line = NULL;
	int status = 0;
	while (i < size)
	{
		fd[i] = open(files[i], O_RDONLY);
		i++;
	}
	j = 0;
	while (j < 10)
	{
		i = 0;
		while (i < size)
		{
			status = get_next_line(fd[i], &line);
			if (status == 1)
				printf("file %d (status: %d): |%s|\n", fd[i], status, line);
			i++;
			line = NULL;
		}
		j++;
	}
	i = 0;
	free(line);
	while (i < size)
		close(fd[i++]);
}

int main()
{
	puts("\033[0;33m*** Test get_next_line\033[0m");

	puts("\n** Regular file");
	cat_file("normal");

	puts("\n** One line file");
	cat_file("one_line");

	puts("\n** Empty file");
	cat_file("empty");

	puts("\n** File that doesn't exist");
	cat_file("000");

	puts("\n** Multiple files");
	char *files2[3] = {"test1", "test2", "test3"};
	cat_files(files2, 3);

	puts("\n** Multiple files, exists, doesn't exist, exists");
	char *files[3] = {"test1", "000", "test3"};
	cat_files(files, 3);

	puts("\n** Double \\n");
	cat_file("double_lb");

	puts("\n** No permission");
	cat_file("no_permission");

	puts("\n** Line of one char");
	cat_file("short_line");

	puts("\n** Random file descriptor");
	char *line = NULL;
	int status = get_next_line(42, &line);
	printf("file 42 (status: %d): |%s|\n", status, line);

	puts("\n** Stdin (ctrl+d to stop)");
	int i = 0;
	char *line2 = NULL;
	int status2 = 0;
	while((status2 = get_next_line(0, &line2)) == 1)
		printf("(status: %d) %d: |%s|\n", status2, i++, line2);
}
