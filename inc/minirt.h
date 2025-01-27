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
typedef struct s_data 
{
    void    *mlx;           //stores pointer returned by mlx init
    void    *win;           //stores pointer to window
    void    *img;           //stores point created by mlx_new_image
    char    *addr;          //
    int     bpp;            // Bits per pixel
    int     line_length;
    int     endian;         //probably not necessary
    int     width;
    int     height;
} t_data;

//FUNCTIONS:

void  is_rt(char *file);
void  init_win(void);
int   handle_key(int keycode, t_data *data);

#endif
