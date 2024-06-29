UNAME = $(shell uname -s) 
NAME = minishell 
CC = gcc 
CFLAGS = -Wall -Wextra -Werror
PREFIX = ${shell find ${HOME} -name arev 2>/dev/null}
SRCS =	$(wildcard src/*/*.c src/*.c src/*/*/*.c src/*/*/*/*.c)
OBJS = $(SRCS:.c=.o) 

READLINE = -lreadline 

ifneq ($(UNAME), Linux) 
	READLINE += -L arev/lib/ 
endif 

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<
	@

all: $(NAME) 

$(NAME): $(OBJS) 
	@$(CC) ${CFLAGS} $(OBJS) $(READLINE) -o  $(NAME)

clean: 
	rm -f ./.o  src/*/*.o src/*.o src/*/*/*.o src/*/*/*/*.o

fclean: clean 
	rm -f $(NAME)

re: fclean all 

readline: 
	cd readline-master && ./configure --prefix=$(PREFIX)/ && make clean && make && make install 

.PHONY: all clean fclean re readline
