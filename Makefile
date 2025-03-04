# Project name
NAME        = miniRT

# Compiler and flags
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror					\
              -Wno-deprecated-non-prototype	\
              -Wno-deprecated-declarations	\
              -DGL_SILENCE_DEPRECATION
INCLUDES    = -Iincludes -Ilib/libft/includes -Ilib/minilibx -Isrc/get_next_line

# Directories
SRC_DIR     = source
OBJ_DIR     = obj
LIB_DIR     = library
LIBFT_DIR   = $(LIB_DIR)/libft
MLX_DIR     = $(LIB_DIR)/minilibx

# Source files and object files
SRC_FILES   = main.c												\
							gnl/get_next_line.c						\
							gnl/get_next_line_utils.c			\
              errors/validate_input.c					\
							window/init.c										\
							window/exit.c										\
							memory/mem_utils.c								\
							parser/read.c										\
							parser/utils.c										\
							parser/parse_scene.c							\
							parser/parse_xyz_rgb.c						\
							parser/parse_shape.c

OBJ_FILES   = $(SRC_FILES:.c=.o)
SRCS        = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS        = $(addprefix $(OBJ_DIR)/, $(OBJ_FILES))

# Libraries
LIBFT       = $(LIBFT_DIR)/libft.a
MLX         = $(MLX_DIR)/libmlx.a
LDFLAGS     = -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -lm \
              -framework OpenGL -framework AppKit

# Rules
all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	@echo "Compiling $(NAME)..."
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)
	@echo "$(NAME) created successfully!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@) # Automatically create subdirectories in obj/
	@echo "Compiling $< to $@"
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@echo "Building libft..."
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	@echo "Building MinilibX..."
	$(MAKE) -C $(MLX_DIR)

clean:
	@echo "Cleaning object files..."
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	@echo "Cleaning $(NAME)..."
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all
