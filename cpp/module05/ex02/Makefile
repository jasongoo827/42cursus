.DEFAULT_GOAL := all

NAME = ex02

CC = c++

CFLAGS = -Wall -Werror -Wextra -MMD -MP -std=c++98

RM = rm -f

SRCS = main.cpp Bureaucrat.cpp Form.cpp

OBJS = $(SRCS:%.cpp=%.o)

DEPS = $(SRCS:%.cpp=%.d)

-include $(DEPS)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o	: %.cpp
	$(CC) $(CFLAGS)  -c -o $@ $<

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
