.DEFAULT_GOAL := all

NAME = megaphone

CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98

RM = rm -f

SRCS = megaphone.cpp
OBJS = $(SRCS:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o	: %.cpp
	$(CC) $(CFLAGS)  -c -o $@ $<

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
