NAME = fractol

SRC_DIR = src
STACK_DIR = $(SRC_DIR)/stack
ALGORITHM_DIR = $(SRC_DIR)/algorithm
UTILS_DIR = $(SRC_DIR)/utils

SOURCES = $(wildcard $(SRC_DIR)/*.c)

CFLAGS = -Wall -Wextra -Werror
LIBFLAGS = -L. -lmlx42 -ldl -lglfw -pthread -lm
MY_HEADER = ./includes/
MLX42 = libmlx42.a

OBJ_DIR = obj
OBJECTS = $(addprefix $(OBJ_DIR)/,$(notdir $(SOURCES:.c=.o)))

.PHONY: all clean fclean re

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	gcc $(CFLAGS) -I $(MY_HEADER) -c $< -o $@

$(NAME): $(OBJECTS)
	cc $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIBFLAGS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all