#include "../includes/minirt.h"

#include <stdio.h>

void init_scene(t_scene_data *scene)
{
    scene->spheres = NULL;
    scene->planes = NULL;
    scene->cylinders = NULL;
    scene->cones = NULL;
    scene->triangles = NULL;
    scene->discs = NULL;
    
    scene->sphere_c = 0;
    scene->plane_c = 0;
    scene->cylinder_c = 0;
    scene->cone_c = 0;
    scene->triangle_c = 0;
    scene->disc_c = 0; 
}

void print_scene_data(const t_scene_data *scene)
{
    int i;

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
    
    // Print Sphere Data
    if (scene->sphere_c > 0)
    {
        printf("=== Spheres (%d) ===\n", scene->sphere_c);
        for (i = 0; i < scene->sphere_c; i++)
        {
            printf("Sphere %d:\n", i + 1);
            printf("  Center: (%.2f, %.2f, %.2f)\n",
                   scene->spheres[i].center.x,
                   scene->spheres[i].center.y,
                   scene->spheres[i].center.z);
            printf("  Diameter: %.2f\n", scene->spheres[i].diameter);
            printf("  Color: R:%d, G:%d, B:%d\n",
                   scene->spheres[i].colour.r,
                   scene->spheres[i].colour.g,
                   scene->spheres[i].colour.b);
            printf("\n");
        }
    }
    
    // Print Plane Data
    if (scene->plane_c > 0)
    {
        printf("=== Planes (%d) ===\n", scene->plane_c);
        for (i = 0; i < scene->plane_c; i++)
        {
            printf("Plane %d:\n", i + 1);
            printf("  Position: (%.2f, %.2f, %.2f)\n",
                   scene->planes[i].position.x,
                   scene->planes[i].position.y,
                   scene->planes[i].position.z);
            printf("  Normal: (%.2f, %.2f, %.2f)\n",
                   scene->planes[i].normal.x,
                   scene->planes[i].normal.y,
                   scene->planes[i].normal.z);
            printf("  Color: R:%d, G:%d, B:%d\n",
                   scene->planes[i].colour.r,
                   scene->planes[i].colour.g,
                   scene->planes[i].colour.b);
            printf("\n");
        }
    }
    
    // Print Cylinder Data
    if (scene->cylinder_c > 0)
    {
        printf("=== Cylinders (%d) ===\n", scene->cylinder_c);
        for (i = 0; i < scene->cylinder_c; i++)
        {
            printf("Cylinder %d:\n", i + 1);
            printf("  Position: (%.2f, %.2f, %.2f)\n",
                   scene->cylinders[i].position.x,
                   scene->cylinders[i].position.y,
                   scene->cylinders[i].position.z);
            printf("  Axis: (%.2f, %.2f, %.2f)\n",
                   scene->cylinders[i].axis.x,
                   scene->cylinders[i].axis.y,
                   scene->cylinders[i].axis.z);
            printf("  Diameter: %.2f\n", scene->cylinders[i].diameter);
            printf("  Height: %.2f\n", scene->cylinders[i].height);
            printf("  Color: R:%d, G:%d, B:%d\n",
                   scene->cylinders[i].colour.r,
                   scene->cylinders[i].colour.g,
                   scene->cylinders[i].colour.b);
            printf("\n");
        }
    }
    
    // Print Cone Data
    if (scene->cone_c > 0)
    {
        printf("=== Cones (%d) ===\n", scene->cone_c);
        for (i = 0; i < scene->cone_c; i++)
        {
            printf("Cone %d:\n", i + 1);
            printf("  Vertex: (%.2f, %.2f, %.2f)\n",
                   scene->cones[i].vertex.x,
                   scene->cones[i].vertex.y,
                   scene->cones[i].vertex.z);
            printf("  Axis: (%.2f, %.2f, %.2f)\n",
                   scene->cones[i].axis.x,
                   scene->cones[i].axis.y,
                   scene->cones[i].axis.z);
            printf("  Angle: %.2f radians\n", scene->cones[i].angle);
            printf("  Height: %.2f\n", scene->cones[i].height);
            printf("  Color: R:%d, G:%d, B:%d\n",
                   scene->cones[i].colour.r,
                   scene->cones[i].colour.g,
                   scene->cones[i].colour.b);
            printf("\n");
        }
    }
    
    // Print Triangle Data
    if (scene->triangle_c > 0)
    {
        printf("=== Triangles (%d) ===\n", scene->triangle_c);
        for (i = 0; i < scene->triangle_c; i++)
        {
            printf("Triangle %d:\n", i + 1);
            printf("  Vertex 1: (%.2f, %.2f, %.2f)\n",
                   scene->triangles[i].v1.x,
                   scene->triangles[i].v1.y,
                   scene->triangles[i].v1.z);
            printf("  Vertex 2: (%.2f, %.2f, %.2f)\n",
                   scene->triangles[i].v2.x,
                   scene->triangles[i].v2.y,
                   scene->triangles[i].v2.z);
            printf("  Vertex 3: (%.2f, %.2f, %.2f)\n",
                   scene->triangles[i].v3.x,
                   scene->triangles[i].v3.y,
                   scene->triangles[i].v3.z);
            printf("  Color: R:%d, G:%d, B:%d\n",
                   scene->triangles[i].colour.r,
                   scene->triangles[i].colour.g,
                   scene->triangles[i].colour.b);
            printf("\n");
        }
    }
    
    // Print Disc Data
    if (scene->disc_c > 0)
    {
        printf("=== Discs (%d) ===\n", scene->disc_c);
        for (i = 0; i < scene->disc_c; i++)
        {
            printf("Disc %d:\n", i + 1);
            printf("  Center: (%.2f, %.2f, %.2f)\n",
                   scene->discs[i].center.x,
                   scene->discs[i].center.y,
                   scene->discs[i].center.z);
            printf("  Normal: (%.2f, %.2f, %.2f)\n",
                   scene->discs[i].normal.x,
                   scene->discs[i].normal.y,
                   scene->discs[i].normal.z);
            printf("  Radius: %.2f\n", scene->discs[i].radius);
            printf("  Color: R:%d, G:%d, B:%d\n",
                   scene->discs[i].colour.r,
                   scene->discs[i].colour.g,
                   scene->discs[i].colour.b);
            printf("\n");
        }
    }
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
  init_scene(&data.scene_data);
  parse_rt(argv[1], &data);
  print_scene_data(&data.scene_data);
  init_win(&data);
}
