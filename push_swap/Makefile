.DEFAULT_GOAL := all

NAME = push_swap

BNS = checker

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCS_PS = main.c data_struct.c operate.c parse.c stack_adt.c utils.c utils2.c radix_sort.c hard_code.c hard_code_utils.c

SRCS_LIB = $(SUB_LIBDIR)/ft_isalpha.c $(SUB_LIBDIR)/ft_isdigit.c $(SUB_LIBDIR)/ft_isalnum.c $(SUB_LIBDIR)/ft_isascii.c \
$(SUB_LIBDIR)/ft_isprint.c $(SUB_LIBDIR)/ft_strlen.c $(SUB_LIBDIR)/ft_memset.c $(SUB_LIBDIR)/ft_bzero.c \
$(SUB_LIBDIR)/ft_memcpy.c $(SUB_LIBDIR)/ft_memmove.c $(SUB_LIBDIR)/ft_strlcpy.c $(SUB_LIBDIR)/ft_strlcat.c \
$(SUB_LIBDIR)/ft_toupper.c $(SUB_LIBDIR)/ft_tolower.c $(SUB_LIBDIR)/ft_strchr.c $(SUB_LIBDIR)/ft_strrchr.c \
$(SUB_LIBDIR)/ft_strncmp.c $(SUB_LIBDIR)/ft_memchr.c $(SUB_LIBDIR)/ft_memcmp.c $(SUB_LIBDIR)/ft_strnstr.c \
$(SUB_LIBDIR)/ft_atoi.c $(SUB_LIBDIR)/ft_calloc.c $(SUB_LIBDIR)/ft_strdup.c $(SUB_LIBDIR)/ft_substr.c \
$(SUB_LIBDIR)/ft_strjoin.c $(SUB_LIBDIR)/ft_strtrim.c $(SUB_LIBDIR)/ft_split.c $(SUB_LIBDIR)/ft_itoa.c \
$(SUB_LIBDIR)/ft_strmapi.c $(SUB_LIBDIR)/ft_striteri.c $(SUB_LIBDIR)/ft_putchar_fd.c $(SUB_LIBDIR)/ft_putstr_fd.c \
$(SUB_LIBDIR)/ft_putendl_fd.c $(SUB_LIBDIR)/ft_putnbr_fd.c $(SUB_LIBDIR)/ft_lstnew.c $(SUB_LIBDIR)/ft_lstadd_front.c \
$(SUB_LIBDIR)/ft_lstsize.c $(SUB_LIBDIR)/ft_lstlast.c $(SUB_LIBDIR)/ft_lstadd_back.c $(SUB_LIBDIR)/ft_lstdelone.c \
$(SUB_LIBDIR)/ft_lstclear.c $(SUB_LIBDIR)/ft_lstiter.c $(SUB_LIBDIR)/ft_lstmap.c 

SRCS_PF = $(SUB_PFDIR)/main.c $(SUB_PFDIR)/ft_printf.c $(SUB_PFDIR)/ft_utils.c $(SUB_PFDIR)/ft_utils2.c $(SUB_PFDIR)/ft_parse.c \
$(SUB_PFDIR)/ft_parse_utils.c $(SUB_PFDIR)/ft_write_by_type.c $(SUB_PFDIR)/ft_write_by_type2.c $(SUB_PFDIR)/ft_write_utils.c \
$(SUB_PFDIR)/ft_write_utils2.c $(SUB_PFDIR)/ft_write_utils3.c

BNS_SRCS = $(BNS_DIR)/data_struct_bonus.c $(BNS_DIR)/main_bonus.c $(BNS_DIR)/operate_bonus.c $(BNS_DIR)/parse_bonus.c $(BNS_DIR)/stack_adt_bonus.c $(BNS_DIR)/utils_bonus.c $(BNS_DIR)/execute_cmd_bonus.c\
$(BNS_DIR)/get_next_line.c $(BNS_DIR)/get_next_line_utils.c

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
	
$(NAME): $(OBJS) $(SUB_LIBDIR)/$(SUB_LIB) $(SUB_PFDIR)/$(SUB_PF)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -I$(SUB_LIBDIR) $(SUB_LIBDIR)/$(SUB_LIB) -I$(SUB_PFDIR) $(SUB_PFDIR)/$(SUB_PF)

$(SUB_LIBDIR)/$(SUB_LIB) : $(SRCS_LIB)
	make -C $(SUB_LIBDIR)

$(SUB_PFDIR)/$(SUB_PF) : $(SRCS_PF)
	make -C $(SUB_PFDIR)

%.o : %.c $(INC)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	make -C $(SUB_LIBDIR) clean
	make -C $(SUB_PFDIR) clean
	$(RM) $(OBJS) $(BNS_OBJS)

fclean: clean
	make -C $(SUB_LIBDIR) fclean
	make -C $(SUB_PFDIR) fclean
	$(RM) $(NAME) $(BNS)

re: fclean all

.PHONY: all bonus clean fclean re
