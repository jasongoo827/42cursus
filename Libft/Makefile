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

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -MMD -MP

RM = rm -f

SRCS = ft_isalpha.c \
	   ft_isdigit.c \
	   ft_isalnum.c \
	   ft_isascii.c \
	   ft_isprint.c \
	   ft_strlen.c \
	   ft_memset.c \
	   ft_bzero.c \
	   ft_memcpy.c \
	   ft_memmove.c \
	   ft_strlcpy.c \
	   ft_strlcat.c \
	   ft_toupper.c \
	   ft_tolower.c \
	   ft_strchr.c \
	   ft_strrchr.c \
	   ft_strncmp.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_strnstr.c \
	   ft_atoi.c \
	   ft_calloc.c \
	   ft_strdup.c \
	   ft_substr.c \
	   ft_strjoin.c \
	   ft_strtrim.c \
	   ft_split.c \
	   ft_itoa.c \
	   ft_strmapi.c \
	   ft_striteri.c \
	   ft_putchar_fd.c \
	   ft_putstr_fd.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c

BNS_SRCS = ft_lstnew.c \
		   ft_lstadd_front.c \
		   ft_lstsize.c \
		   ft_lstlast.c \
		   ft_lstadd_back.c \
		   ft_lstdelone.c \
		   ft_lstclear.c \
		   ft_lstiter.c \
		   ft_lstmap.c

OBJS = $(SRCS:%.c=%.o)
BNS_OBJS = $(BNS_SRCS:%.c=%.o)
DEPS = $(SRCS:%.c=%.d)
BNS_DEPS = $(BNS_SRCS:%.c=%.d)
-include $(DEPS)
-include $(BNS_DEPS)

all: make_mandatory

make_mandatory : $(OBJS)
	$(CC) $(FLAGS) -c $(SRCS) -I./
	ar rc $(NAME) $(OBJS)
	touch $@

bonus: make_bonus

make_bonus: $(BNS_OBJS)
	$(CC) $(FLAGS) -c $(BNS_SRCS) -I./
	ar rc $(NAME) $(BNS_OBJS)
	touch $@

clean:
	$(RM) $(OBJS) $(BNS_OBJS)
	$(RM) $(DEPS) $(BNS_DEPS)
	$(RM) make_mandatory make_bonus

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
