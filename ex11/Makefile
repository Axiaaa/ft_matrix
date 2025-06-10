NAME = ex11
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)
INCLUDES = -I../includes
COMPILO = c++
FLAGS = -Wall -Wextra -Werror -std=c++17 -MMD -MP -g3 
BUILD_DIR = .build
BUILD_OBJS = $(addprefix $(BUILD_DIR)/, $(OBJS))
BUILD_DEPS = $(addprefix $(BUILD_DIR)/, $(DEPS))

all: $(NAME)

$(NAME): $(BUILD_OBJS)
	c++ $(FLAGS) $(BUILD_OBJS) -o $(NAME)

$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	$(COMPILO) $(FLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(BUILD_DEPS)

.PHONY: all clean fclean re
