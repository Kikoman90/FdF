make -C libft/ fclean && make -C libft/
clang -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
clang -o FdF main.o -I libft/includes -L libft/ -lft -lmlx -framework OpenGL -framework AppKit
