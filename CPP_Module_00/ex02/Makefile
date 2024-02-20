NAME = gbunited

SRC = Account.cpp tests.cpp
OBJ = $(SRC:%.cpp=%.o)
DEPS = $(OBJ:%.o=%.d)

MAKEFILE = Makefile

CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98 -MMD

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp $(MAKEFILE)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(RM) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

log: all
	./$(NAME) > $(shell date +'%Y%m%d_%H%M%S').log

.PHONY: all clean fclean re log
-include $(DEPS)
