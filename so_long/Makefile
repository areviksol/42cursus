NAME 	= so_long

CC 		= gcc

CFLAGS 	= -Wall -Wextra -Werror

SRCS 	=	 so_long.c getmap.c \
			./get_next_line/get_next_line_utils.c	\
			./get_next_line/get_next_line.c			\
			split.c filevalid.c \
			mapvalid.c utils.c \
			render.c move.c more_utils.c\

all: $(NAME)

OBJS	= $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	@$(CC) -lmlx -framework OpenGL -framework AppKit  $^ -o $@
%.o:%.c
	@$(CC) $(CFLAGS) -c $^ -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
