PROG = so_long
SRCS = src/main.c
OBJS = $(SRCS:.c=.o)

all: $(PROG)

%.o: %.c
	gcc -Wall -Wextra -Werror -I./minilibx -c $< -o $@

$(PROG): $(OBJS)
	gcc $(OBJS) -L/usr/lib -L./minilibx -I./minilibx -lmlx -lXext -lX11 -lm -lz -o $(PROG)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(PROG)

re: fclean all

.PHONY: all clean fclean re