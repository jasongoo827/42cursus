.DEFAULT_GOAL := all

NAME = PmergeMe

CC = c++

CFLAGS = -Wall -Werror -Wextra -MMD -MP -std=c++98 -g

RM = rm -f

SRCS = PmergeMe.cpp main.cpp

OBJS = $(SRCS:%.cpp=%.o)

DEPS = $(SRCS:%.cpp=%.d)

-include $(DEPS)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o	: %.cpp
	$(CC) $(CFLAGS)  -c $< -o $@

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re