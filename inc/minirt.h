#ifndef MINIRT_H
#define MINIRT_H

// Standard libraries
#include <stdlib.h>     // For malloc, free, exit
#include <stdio.h>      // For printf, perror
#include <unistd.h>     // For open, close, read, write
#include <fcntl.h>      // For file opening flags
#include <string.h>     // For strerror
#include "../src/gnl/get_next_line.h"
#include "../lib/minilibx/mlx.h"
#include "../lib/libft/libft.h"

// Math library
#include <math.h>       // For mathematical functions (compile with -lm)

// Additional utilities (if needed)
#include <errno.h>      // For error codes

// Define structures, constants, and function prototypes here if necessary
typedef struct s_mlx_data 
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
} t_mlx_data;

typedef struct s_xyz
{
  float x;
  float y;
  float z;
} t_xyz;

typedef struct s_rgb
{
  int r;
  int g;
  int b;
} t_rgb;

typedef struct s_ambient 
{
  float     intensity;
  t_rgb     colour;
} t_ambient;

typedef struct s_camera
{
  t_xyz     position;
  t_xyz     orientation;
  float     fov;
} t_camera;

typedef struct s_light
{
  float   intensity;
  t_rgb   colour;
  t_xyz   source;
} t_light;

typedef struct s_scene_data
{
  t_ambient ambient;
  t_camera  camera;
  t_light   light;
  // SHAPES + NUM OF SHAPES
} t_scene_data;

typedef struct s_data 
{
    t_mlx_data    mlx_data;
    t_scene_data  scene_data;
} t_data;

void    is_rt(char *file);
void    init_win(t_data *data);
int     handle_key(int keycode, t_data *data);
void    parse_rt(const char *filename, t_data *data);
void    parse_line(char *line, t_scene_data *scene); 
void    free_tokens(char **tokens);
void    parse_ambient(char **tokens, t_scene_data *scene);
void    parse_camera(char **tokens, t_scene_data *scene);
void    parse_light(char **tokens, t_scene_data *scene);
t_xyz   parse_xyz(const char *str);
t_rgb   parse_rgb(const char *str);
double  ft_atof(const char *str);

#endif
