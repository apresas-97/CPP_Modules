NAME = moar_brainz

SRC = main.cpp Zombie.cpp zombieHorde.cpp
OBJ = $(SRC:%.cpp=%.o)
DEPS = $(OBJ:%.o=%.d)

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
DFLAGS = -MMD

RM = rm -rf

MAKEFILE = Makefile

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp $(MAKEFILE)
	$(CC) $(CFLAGS) $(DFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(RM) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

run: all
	./$(NAME)

leaks: all
	leaks --atExit -- ./$(NAME)

.PHONY: all clean fclean re run leaks
-include $(DEPS)
