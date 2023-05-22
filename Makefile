CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME  = philo
SRCS = checks.c death.c error.c init.c live.c parse.c philo.c utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)


$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -lpthread -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

dre: fclean debug

.PHONY: all, clean, fclean, re, dre
