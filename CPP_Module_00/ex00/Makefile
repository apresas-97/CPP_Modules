NAME = megaphone

SRC = megaphone.cpp
OBJ = $(SRC:%.cpp=%.o)
DEPS = $(OBJ:%.o=%.d)

MAKEFILE = Makefile

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD

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

test: all
	@/bin/echo "Test:"
	@/bin/echo -n "$$>"
	./$(NAME) "shhhhh... I think the students are asleep..."
	@/bin/echo -n "$$>"
	./$(NAME) Damnit " ! " "Sorry students, I thought this thing was off."
	@/bin/echo -n "$$>"
	./$(NAME)
	@/bin/echo -n "$$>"

.PHONY: all clean fclean re test
-include $(DEPS)
