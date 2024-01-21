.DEFAULT_GOAL := all

NAME = pipex

BNS = checker

CC = cc -g

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCS_PS = main.c ft_split.c ft_strjoin.c ft_strlen.c

SUB_LIB = libft.a
SUB_LIBDIR = ./Libft/libft
SUB_PF = libftprintf.a
SUB_PFDIR = ./Libft/ft_printf
SUB_GNLDIR = ./Libft/get_next_line
BNS_DIR = ./bonus

OBJS = $(SRCS_PS:%.c=%.o)
BNS_OBJS = $(BNS_SRCS:%.c=%.o)
INC = push_swap.h
BNS_INC = bonus/push_swap_bonus.h

ifdef ADD_BNS
	OBJS := $(BNS_OBJS)
	INC := $(BNS_INC)
	NAME := $(BNS)
endif

all: $(NAME)

bonus:
	@ADD_BNS=1 make
	
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

# $(SUB_LIBDIR)/$(SUB_LIB) : $(SRCS_LIB)
# 	make -C $(SUB_LIBDIR)

# $(SUB_PFDIR)/$(SUB_PF) : $(SRCS_PF)
# 	make -C $(SUB_PFDIR)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJS) $(BNS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
