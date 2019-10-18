#!/bin/bash
echo "** Norminette"
# norminette get*.[ch]
echo "** Compilation"
gcc -Wextra -Werror -Wall -D BUFFER_SIZE=100000 -g3 -fsanitize=address main.c get_next_line.c get_next_line_utils.c
echo "** Run"
./a.out
