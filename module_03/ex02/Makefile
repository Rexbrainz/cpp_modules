#**************************************************************************** #
#								   INHERITANCE                                #
# *************************************************************************** #

NAME        = inheritance
CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -std=c++17

SRC_DIR     = src
OBJ_DIR     = obj
INC_DIR     = include

SRCS        = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
OBJ        = $(SRCS:.cpp=.o)

# Colors
GREEN       = \033[0;32m
RED         = \033[0;31m
RESET       = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) -o $@ $^
	@echo "$(GREEN)Compiled $(NAME) successfully!$(RESET)"

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ)
	@echo "$(RED)Object files cleaned.$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)Executable $(NAME) removed.$(RESET)"

re: fclean all

.PHONY: all clean fclean re

