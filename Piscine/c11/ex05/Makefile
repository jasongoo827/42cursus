MAKEFLAGS += --silent

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCS = srcs/ft_atoi.c srcs/ft_calculate.c srcs/ft_putchar.c srcs/ft_putnbr.c srcs/main.c

NAME = do-op

OBJS = $(SRCS:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

$(NAME) : $(OBJS)
	$(CC) -o $@ $(OBJS)

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all
