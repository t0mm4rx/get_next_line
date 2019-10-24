#!/bin/sh
gcc -g3 -fsanitize=address -D BUFFER_SIZE=$1 ../get_next_line.c ../get_next_line_utils.c main.c  && ./a.out $2
