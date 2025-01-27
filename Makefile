# Project name
NAME        = miniRT

# Compiler and flags
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror \
              -Wno-deprecated-non-prototype \
              -Wno-deprecated-declarations \
              -DGL_SILENCE_DEPRECATION
INCLUDES    = -Iincludes -Ilib/libft/includes -Ilib/minilibx

# Directories
SRC_DIR     = src
OBJ_DIR     = obj
LIB_DIR     = lib
LIBFT_DIR   = $(LIB_DIR)/libft
MLX_DIR     = $(LIB_DIR)/minilibx

# Source files and object files
SRC_FILES   = main.c \
              err/validate_input.c \
							win/init.c \
							win/exit.c
								
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
