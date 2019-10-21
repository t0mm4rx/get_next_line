#!/bin/sh
gcc main.c ../get_next_line_bonus.c ../get_next_line_utils_bonus.c -g3 -fsanitize=address -D BUFFER_SIZE=$1 -Wall -Werror -Wextra && ./a.out
