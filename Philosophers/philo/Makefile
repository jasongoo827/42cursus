.DEFAULT_GOAL := all

NAME = philo

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

RM = rm -f

SRCS = main.c init_struct.c utils.c essentials.c routine.c
OBJS = $(SRCS:%.c=%.o)
# BNS_SRCS = 
# BNS_OBJS = $(BNS_SRCS:%.c=%.o)
# BNS_DIR = ./bonus

# BNS_INC = bonus/fdf_bonus.h
# INC = fdf.h

# ifdef ADD_BNS
# 	OBJS := $(BNS_OBJS)
# 	INC := $(BNS_INC)
# endif

all: $(NAME)

# bonus: 
# 	@ADD_BNS=1 make

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o	: %.c
	$(CC) $(CFLAGS)  -c -o $@ $<

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
