.DEFAULT_GOAL := all

NAME = ex01

CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98

RM = rm -f

SRCS = main.cpp Contact.cpp PhoneBook.cpp 

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

.PHONY: all bonus clean fclean re
