#!/bin/sh
gcc main.c ../get_next_line.c ../get_next_line_utils.c -g3 -fsanitize=address -D BUFFER_SIZE=$1 -Wall -Werror -Wextra && ./a.out
