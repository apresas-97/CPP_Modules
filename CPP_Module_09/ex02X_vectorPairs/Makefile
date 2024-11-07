NAME = PmergeMe

# Files
SRC_DIR = .
OBJ_DIR = obj
DEPS_DIR = deps

SRC =	main.cpp \
		parse_arguments.cpp \
		print_container.cpp \
		verify_sort.cpp \
		PmergeMe.cpp \
		VIteratorP.cpp \
		LIterator.cpp \
		merge_insertion_sort_vector.cpp \
		merge_insertion_sort_list.cpp \
		jacobsthal_sequence.cpp \
		time_utils.cpp
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:%.cpp=%.o))
DEPS = $(addprefix $(DEPS_DIR)/,$(SRC:%.cpp=%.d))

# Libraries and Headers
LIBS =
HDRS =

# Compiler + flags
CC = c++
CFLAGS = -Wall -Wextra -Werror -g -std=c++98 -O2
DFLAGS = -MD -MF
INCLUDE =

# Commands and utils
RM = rm -rf
MKDIR = mkdir -p
AR = ar rcs
MUTE = &> /dev/null
MK = Makefile

SIZE ?= 3000
LOOPS ?= 10

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
	./$(NAME) `shuf -i 1-$(SIZE) -n $(SIZE) | tr "\n" " "`

run_loop: all
	i=0; \
	while [ $$i -lt $(LOOPS) ]; do \
		echo "Running iteration $$i"; \
		./$(NAME) `shuf -i 1-$(SIZE) -n $(SIZE) | tr "\n" " "`; \
		i=$$((i + 1)); \
	done

case: all
	./$(NAME) 5 2 3 1 4 7 6

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) `shuf -i 1-$(SIZE) -n $(SIZE) | tr "\n" " "`

.PHONY: all clean fclean re run run_loop case valgrind
-include $(DEPS)
