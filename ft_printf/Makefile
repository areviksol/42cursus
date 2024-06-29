# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aremkrtc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/15 19:25:02 by aremkrtc          #+#    #+#              #
#    Updated: 2022/04/15 19:25:09 by aremkrtc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = $(shell find "." -name "*.c")
 	 
OBJS = $(SRCS:.c=.o)

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -I.

NAME = libftprintf.a

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -c $(SRCS)
	ar rc ${NAME} $(OBJS)
	ranlib ${NAME}

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re
