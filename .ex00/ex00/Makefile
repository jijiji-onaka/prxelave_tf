# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/09 20:39:54 by tjinichi          #+#    #+#              #
#    Updated: 2020/04/10 03:38:32 by tjinichi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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
