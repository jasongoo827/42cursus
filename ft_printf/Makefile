# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgoo <jgoo@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/11 12:21:46 by jgoo              #+#    #+#              #
#    Updated: 2023/10/18 15:09:48 by jgoo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL := all

NAME = libftprintf.a

RM = rm -f

SRCS = main.c \
	   ft_printf.c \
	   ft_utils.c \
	   ft_utils2.c \
	   ft_parse.c \
	   ft_parse_utils.c \
	   ft_write_by_type.c \
	   ft_write_by_type2.c \
	   ft_write_utils.c \
	   ft_write_utils2.c \
	   ft_write_utils3.c

BNS_SRCS = bonus/main_bonus.c \
		   bonus/ft_printf_bonus.c \
		   bonus/ft_utils_bonus.c \
		   bonus/ft_utils2_bonus.c \
		   bonus/ft_parse_bonus.c \
		   bonus/ft_parse_utils_bonus.c \
		   bonus/ft_write_by_type_bonus.c \
		   bonus/ft_write_by_type2_bonus.c \
		   bonus/ft_write_utils_bonus.c \
		   bonus/ft_write_utils2_bonus.c \
		   bonus/ft_write_utils3_bonus.c

OBJS = $(SRCS:%.c=%.o)
BNS_OBJS = $(BNS_SRCS:%.c=%.o)
INC = ft_printf.h
BNS_INC = bonus/ft_printf_bonus.h

ifdef ADD_BNS
	OBJS := $(BNS_OBJS)
	INC := $(BNS_INC)
endif

all: $(NAME)

bonus:
	@ADD_BNS=1 make
	
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJS) $(BNS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
