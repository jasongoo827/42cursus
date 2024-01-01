CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIBS = ar rc

RM = rm -f

INC = includes

SRCS = srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c srcs/ft_strlen.c srcs/ft_swap.c

OBJ_DIR = ./srcs

TARGET = libft.a

OBJS = $(SRCS:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o} -I ${INC}

$(TARGET) : $(OBJS)
	$(LIBS) $@ $(OBJS)

all: ${TARGET}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${TARGET}

re: fclean all