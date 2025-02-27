#include "../../includes/minirt.h"

void parse_ambient(char **tokens, t_scene_data *scene)
{
  if (!tokens[1] || !tokens[2])
  {
    printf("Error parsing token");
    exit(EXIT_FAILURE);
  }
  scene->ambient.intensity = atof(tokens[1]);
  scene->ambient.colour = parse_rgb(tokens[2]);
}

void parse_camera(char **tokens, t_scene_data *scene)
{
  if (!tokens[1] || !tokens[2] || !tokens[3])
  {
    printf("Error parsing token");
    exit(EXIT_FAILURE);
  }
  scene->camera.position = parse_xyz(tokens[1]);
  scene->camera.orientation = parse_xyz(tokens[2]);
  scene->camera.fov = atof(tokens[3]);
}

void parse_light(char **tokens, t_scene_data *scene)
{
  if (!tokens[1] || !tokens[2] || !tokens[3])
  {
    printf("Error parsing L Token");
    exit(EXIT_FAILURE);
  }
  scene->light.source = parse_xyz(tokens[1]);
  scene->light.intensity = atof(tokens[2]);
  scene->light.colour = parse_rgb(tokens[3]);
}
