#include "../../includes/minirt.h"

/*
 * Line 1: A (Ambient lighting) 0.2 (intensity) 255, 255, 255 (colour of ambient light)
 * Line 2: C (camera) 0,0,0 (position of camera) 0,0,1 Orientation of camera as normalized vector) 60 (FOV in degrees)
 * Line 3: L (Light Source) 0,0,0 (position of light in scene)
 * Line 4: cy (cylinder object) 0,0,50 (position of cylinder base) 1,1,1 (Orientation of cylinder as vector) 16 (diameter of cylinder) 20 (height of the cylinder) 255,0,0 (RGB colour of the cylinder)
 *
*/

void parse_line(char *line, t_scene_data *scene)
{
  char **tokens;

  tokens = ft_split(line, ' ');
  if (!tokens || !tokens[0])
  {
    //free_tokens(tokens);
    return;
  }
  if (ft_strncmp(tokens[0], "A", ft_strlen("A") + 1) == 0)
    parse_ambient(tokens, scene);
  else if (ft_strncmp(tokens[0], "C", ft_strlen("C") + 1) == 0)
    parse_camera(tokens, scene);
  else if (ft_strncmp(tokens[0], "L", ft_strlen("L") + 1) == 0)
    parse_light(tokens, scene);
  else if (ft_strlen(tokens[0]) == 2)
    parse_shape(tokens, scene);
  else
    printf("Error: Unknown Element Type = %s\n", tokens[0]);
  free_tokens(tokens);
}

void parse_rt(const char *filename, t_data *data)
{
  int fd;
  char *line;

  fd = open(filename, O_RDONLY);
  if (fd < 0)
  {
    perror("Error opening file");
    exit(EXIT_FAILURE);
  }
  while((line = get_next_line(fd)) != NULL)
  {
    if (line[0] == '\0' || line[0] == '\n' || line[0] == '#')
    {
      free(line);
      continue ;
    }
    parse_line(line, &data->scene_data);
    free(line);
  }
  close(fd);
}
