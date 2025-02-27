#include "../../includes/minirt.h"

t_rgb parse_rgb(const char *str)
{
  t_rgb rgb;
  char  **tokens;
  int   i;

  tokens = ft_split(str, ',');
  i = 0;
  while (tokens && tokens[i])
    i++;
  if (i != 3)
  {
    printf("Error parsing rgb values");
    free_tokens(tokens);
    exit(EXIT_FAILURE);
  }
  rgb.r = ft_atoi(tokens[0]);
  rgb.g = ft_atoi(tokens[1]);
  rgb.b = ft_atoi(tokens[2]);
  free_tokens(tokens);
  return (rgb);
}

t_xyz parse_xyz(const char *str)
{
  t_xyz xyz;
  char  **tokens;
  int   i;

  tokens = ft_split(str, ',');
  i = 0;
  while (tokens && tokens[i])
    i++;
  if (i != 3)
  {
    printf("Error parsing xyz values");
    free_tokens(tokens);
    exit(EXIT_FAILURE);
  }
  xyz.x = ft_atoi(tokens[0]);
  xyz.y = ft_atoi(tokens[1]);
  xyz.z = ft_atoi(tokens[2]);
  return (xyz);
}
