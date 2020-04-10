

NAME = eval_expr
SRCS = srcs/*.c
OBJS = ./*.o
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
		gcc -c $(CFLAGS) $(SRCS)
		gcc -o $(NAME) $(OBJS)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all
