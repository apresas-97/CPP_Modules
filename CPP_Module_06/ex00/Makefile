NAME = convert

# Files
SRC_DIR = .
OBJ_DIR = obj
DEPS_DIR = deps

SRC = main.cpp ScalarConverter.cpp
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:%.cpp=%.o))
DEPS = $(addprefix $(DEPS_DIR)/,$(SRC:%.cpp=%.d))

# Libraries and Headers
LIBS =
HDRS =

# Compiler + flags
CC = c++
CFLAGS = -Wall -Wextra -Werror -g -std=c++98
DFLAGS = -MD -MF
INCLUDE =

# Commands and utils
RM = rm -rf
MKDIR = mkdir -p
AR = ar rcs
MUTE = &> /dev/null
MK = Makefile

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(MK) | $(OBJ_DIR) $(DEPS_DIR)
	$(CC) $(CFLAGS) $(DFLAGS) $(DEPS_DIR)/$*.d -c $< -o $@

$(OBJ_DIR):
	@$(MKDIR) $(OBJ_DIR)

$(DEPS_DIR):
	@$(MKDIR) $(DEPS_DIR)

clean:
	@$(RM) $(OBJ)
	@$(RM) $(OBJ_DIR)
	@$(RM) $(DEPS)
	@$(RM) $(DEPS_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

run: all
	./$(NAME)

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

test: all
	@echo "Testing chars:"
	./$(NAME) a
	@echo "----------------------------"
	./$(NAME) A
	@echo "----------------------------"
	./$(NAME) -
	@echo "----------------------------"
	./$(NAME) 0
	@echo "----------------------------"
	./$(NAME) ]
	@echo "----------------------------"
	./$(NAME) ">"
	@echo "----------------------------"
	./$(NAME) " "
	@echo "----------------------------"
	./$(NAME) "~"
	@echo "----------------------------"
	@echo "Testing ints:"
	./$(NAME) 0
	@echo "----------------------------"
	./$(NAME) 42
	@echo "----------------------------"
	./$(NAME) -95138
	@echo "----------------------------"
	./$(NAME) -0
	@echo "----------------------------"
	./$(NAME) 501359
	@echo "----------------------------"
	./$(NAME) -42
	@echo "----------------------------"
	./$(NAME) -0000000000000001
	@echo "----------------------------"
	./$(NAME) 91039485
	@echo "----------------------------"
	./$(NAME) 2147483647
	@echo "----------------------------"
	./$(NAME) -2147483648
	@echo "----------------------------"
	./$(NAME) 2147483648
	@echo "----------------------------"
	./$(NAME) -2147483649
	@echo "----------------------------"
	@echo "Testing floats:"
	./$(NAME) 42.0f
	@echo "----------------------------"
	./$(NAME) 0.0f
	@echo "----------------------------"
	./$(NAME) -0.00000f
	@echo "----------------------------"
	./$(NAME) 13579.2468f
	@echo "----------------------------"
	./$(NAME) -9995813.0311f
	@echo "----------------------------"
	./$(NAME) 0.f
	@echo "----------------------------"
	./$(NAME) .3f
	@echo "----------------------------"
	./$(NAME) -inff
	@echo "----------------------------"
	./$(NAME) +inff
	@echo "----------------------------"
	./$(NAME) nanf
	@echo "----------------------------"
	@echo "Testing doubles:"
	./$(NAME) 42.0
	@echo "----------------------------"
	./$(NAME) 0.0
	@echo "----------------------------"
	./$(NAME) -0.00000
	@echo "----------------------------"
	./$(NAME) 13579.2468
	@echo "----------------------------"
	./$(NAME) -9995813.0311
	@echo "----------------------------"
	./$(NAME) 0.
	@echo "----------------------------"
	./$(NAME) .3
	@echo "----------------------------"
	./$(NAME) -inf
	@echo "----------------------------"
	./$(NAME) +inf
	@echo "----------------------------"
	./$(NAME) nan
	@echo "----------------------------"

.PHONY: all clean fclean re run valgrind test
-include $(DEPS)
