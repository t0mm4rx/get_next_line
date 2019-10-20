#!/bin/bash
echo "** Norminette"
#norminette get*.[ch]
echo "** Compilation"
gcc -Wextra -Werror -Wall -D BUFFER_SIZE=100 -g3 -fsanitize=address main.c get_next_line_bonus.c get_next_line_utils_bonus.c
echo "** Run"
./a.out
