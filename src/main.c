#include "../inc/minirt.h"

#include <stdio.h>

void print_scene_data(const t_scene_data *scene)
{
    // Print Ambient Light Data

    printf("DATA PARSING DEBUG\n\n");
    printf("=== Ambient Light ===\n");
    printf("Intensity: %f\n", scene->ambient.intensity);
    printf("Color: R:%d, G:%d, B:%d\n",
           scene->ambient.colour.r,
           scene->ambient.colour.g,
           scene->ambient.colour.b);
    printf("\n");

    // Print Camera Data
    printf("=== Camera ===\n");
    printf("Position: (%.2f, %.2f, %.2f)\n",
           scene->camera.position.x,
           scene->camera.position.y,
           scene->camera.position.z);
    printf("Orientation: (%.2f, %.2f, %.2f)\n",
           scene->camera.orientation.x,
           scene->camera.orientation.y,
           scene->camera.orientation.z);
    printf("FOV: %f\n", scene->camera.fov);
    printf("\n");

    // Print Light Data
    printf("=== Light ===\n");
    printf("Source: (%.2f, %.2f, %.2f)\n",
           scene->light.source.x,
           scene->light.source.y,
           scene->light.source.z);
    printf("Intensity: %f\n", scene->light.intensity);
    printf("Color: R:%d, G:%d, B:%d\n",
           scene->light.colour.r,
           scene->light.colour.g,
           scene->light.colour.b);
    printf("\n");
}

int main(int argc, char *argv[])
{
  t_data data;

  if (argc != 2)
  {
    printf("Incorrect Number of Args Given\n");
    return (1);
  }
  is_rt(argv[1]); 
  parse_rt(argv[1], &data);
  print_scene_data(&data.scene_data);
  init_win(&data);
}
