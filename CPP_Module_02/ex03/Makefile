NAME = harlFilter

# Files
SRC_DIR = .
OBJ_DIR = obj
DEPS_DIR = deps

SRC = main.cpp Harl.cpp
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:%.cpp=%.o))
DEPS = $(addprefix $(DEPS_DIR)/,$(SRC:%.cpp=%.d))

# Libraries and Headers
LIBS =
HDRS =

# Compiler + flags
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
DFLAGS = -MD -MF
INCLUDE =

# Commands and utils
RM = rm --recursive --force --verbose
MKDIR = mkdir --parent --verbose
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

.PHONY: all clean fclean re run
-include $(DEPS)
