.DEFAULT_GOAL := all

NAME = ex03

CC = c++

CFLAGS = -Wall -Werror -Wextra -MMD -MP -std=c++98

RM = rm -f

SRCS = AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp main.cpp

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
