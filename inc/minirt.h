#ifndef MINIRT_H
#define MINIRT_H

// Standard libraries
#include <stdlib.h>     // For malloc, free, exit
#include <stdio.h>      // For printf, perror
#include <unistd.h>     // For open, close, read, write
#include <fcntl.h>      // For file opening flags
#include <string.h>     // For strerror

// MLX and LIBFT
#include "../lib/minilibx/mlx.h"
#include "../lib/libft/libft.h"

// Math library
#include <math.h>       // For mathematical functions (compile with -lm)

// MinilibX
#include "mlx.h"        // Include MinilibX (adjust path if necessary)

// Additional utilities (if needed)
#include <errno.h>      // For error codes

// Define structures, constants, and function prototypes here if necessary

//FUNCTIONS:

void is_rt(char *file);

#endif
