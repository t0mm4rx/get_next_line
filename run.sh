#!/bin/bash
echo "** Norminette"
# norminette get*.[ch]
echo "** Compilation"
gcc -Wextra -Werror -Wall -g3 -fsanitize=address main.c get_next_line.c get_next_line_utils.c
echo "** Run"
./a.out
