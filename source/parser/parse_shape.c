#include "../../includes/minirt.h"

void  parse_sphere(char **tokens, t_scene_data *scene)
{
  int       token_count;
  t_sphere  *sphere;

  token_count = 0;
  while (tokens[token_count])
    token_count++;

  if (token_count != 4)
  {
    printf("Error: sphere definition invalid");
    exit(1);
  }

  if (scene->spheres == NULL)
    scene->spheres = (t_sphere *)malloc(sizeof(t_sphere));
  else
    scene->spheres = (t_sphere *)realloc(scene->spheres, sizeof(t_sphere) * (scene->sphere_c + 1));

  if(!scene->spheres)
  {
    printf("Memory Error: parse_sphere");
    exit(1);
  }

  sphere = &scene->spheres[scene->sphere_c];
  sphere->type = 1;
  sphere->center = parse_xyz(tokens[1]);
  sphere->diameter = ft_atof(tokens[2]);
  sphere->colour = parse_rgb(tokens[3]);

  if (sphere->diameter <= 0)
  {
    printf("Error: sphere definition invalid");
    exit(1);
  }
}

void parse_plane(char **tokens, t_scene_data *scene)
{
    int     token_count;
    t_plane *plane;
    float   length;
    
    token_count = 0;
    while (tokens[token_count])
        token_count++;
    
    if (token_count != 4)
    {
        printf("Error: Plane definition requires 3 parameters\n");
        exit(1);  
    }

    if (scene->planes == NULL)
        scene->planes = (t_plane *)malloc(sizeof(t_plane));
    else
        scene->planes = (t_plane *)realloc(scene->planes, 
                           sizeof(t_plane) * (scene->plane_c + 1));

    if (!scene->planes)
    {
        printf("Error: Memory allocation failed for plane\n");
        exit(1);
    }
    
    plane = &scene->planes[scene->plane_c];
    plane->type = 2;
    plane->position = parse_xyz(tokens[1]);
    plane->normal = parse_xyz(tokens[2]);
    plane->colour = parse_rgb(tokens[3]);
    
    length = sqrt(plane->normal.x * plane->normal.x + 
                  plane->normal.y * plane->normal.y + 
                  plane->normal.z * plane->normal.z);
    
    if (length == 0)
    {
        printf("Error: Plane normal vector cannot be zero\n");
        exit(1);
    }
    
    plane->normal.x /= length;
    plane->normal.y /= length;
    plane->normal.z /= length;
}

void parse_cylinder(char **tokens, t_scene_data *scene)
{
    int         token_count;
    t_cylinder  *cylinder;
    float       length; 
    token_count = 0;
    while (tokens[token_count])
        token_count++;
    
    if (token_count != 6)
    {
        printf("Error: Cylinder definition requires 5 parameters\n");
        exit(1);
    }
    
    if (scene->cylinders == NULL)
        scene->cylinders = (t_cylinder *)malloc(sizeof(t_cylinder));
    else
        scene->cylinders = (t_cylinder *)realloc(scene->cylinders, 
                              sizeof(t_cylinder) * (scene->cylinder_c + 1));
    
    if (!scene->cylinders)
    {
        printf("Error: Memory allocation failed for cylinder\n");
        exit(1);
    }
    
    cylinder = &scene->cylinders[scene->cylinder_c];
    cylinder->type = 3; // Type identifier for cylinder
    cylinder->position = parse_xyz(tokens[1]);
    cylinder->axis = parse_xyz(tokens[2]);
    cylinder->diameter = ft_atof(tokens[3]);
    cylinder->height = ft_atof(tokens[4]);
    cylinder->colour = parse_rgb(tokens[5]);
    
    length = sqrt(cylinder->axis.x * cylinder->axis.x + 
                       cylinder->axis.y * cylinder->axis.y + 
                       cylinder->axis.z * cylinder->axis.z);
    
    if (length == 0)
    {
        printf("Error: Cylinder axis vector cannot be zero\n");
        exit(1);
    }
    
    cylinder->axis.x /= length;
    cylinder->axis.y /= length;
    cylinder->axis.z /= length;
    
    if (cylinder->diameter <= 0 || cylinder->height <= 0)
    {
        printf("Error: Cylinder diameter and height must be positive\n");
        exit(1);
    }
}

void parse_cone(char **tokens, t_scene_data *scene)
{
    int     token_count;
    t_cone  *cone;
    float   length;
    
    token_count = 0;
    while (tokens[token_count])
        token_count++;
    
    if (token_count != 6)
    {
        printf("Error: Cone definition requires 5 parameters\n");
        exit(1);
    }
    
    if (scene->cones == NULL)
        scene->cones = (t_cone *)malloc(sizeof(t_cone));
    else
        scene->cones = (t_cone *)realloc(scene->cones, 
                          sizeof(t_cone) * (scene->cone_c + 1));
    
    if (!scene->cones)
    {
        printf("Error: Memory allocation failed for cone\n");
        exit(1);
    }
    
    cone = &scene->cones[scene->cone_c];
    cone->type = 4;
    cone->vertex = parse_xyz(tokens[1]);
    cone->axis = parse_xyz(tokens[2]);
    cone->angle = ft_atof(tokens[3]);
    cone->height = ft_atof(tokens[4]);
    cone->colour = parse_rgb(tokens[5]);
    
    length = sqrt(cone->axis.x * cone->axis.x + 
                       cone->axis.y * cone->axis.y + 
                       cone->axis.z * cone->axis.z);
    
    if (length == 0)
    {
        printf("Error: Cone axis vector cannot be zero\n");
        exit(1);
    }
    
    cone->axis.x /= length;
    cone->axis.y /= length;
    cone->axis.z /= length;
    
    if (cone->angle <= 0 || cone->angle >= 90 || cone->height <= 0)
    {
        printf("Error: Cone angle must be between 0 and 90, and height must be positive\n");
        exit(1);
    }
        // Convert angle from degrees to radians
    cone->angle = cone->angle * M_PI / 180.0;
}

void parse_triangle(char **tokens, t_scene_data *scene)
{
    int token_count;
    t_triangle *triangle;
    
    token_count = 0;
    while (tokens[token_count])
        token_count++;
    
    if (token_count != 5)
    {
        printf("Error: Triangle definition requires 4 parameters\n");
        exit(1);
    }
    
    if (scene->triangles == NULL)
        scene->triangles = (t_triangle *)malloc(sizeof(t_triangle));
    else
        scene->triangles = (t_triangle *)realloc(scene->triangles, 
                              sizeof(t_triangle) * (scene->triangle_c + 1));
    
    if (!scene->triangles)
    {
        printf("Error: Memory allocation failed for triangle\n");
        exit(1);
    }
    
    triangle = &scene->triangles[scene->triangle_c];
    triangle->type = 5; // Type identifier for triangle
    triangle->v1 = parse_xyz(tokens[1]);
    triangle->v2 = parse_xyz(tokens[2]);
    triangle->v3 = parse_xyz(tokens[3]);
    triangle->colour = parse_rgb(tokens[4]);
}

void parse_disc(char **tokens, t_scene_data *scene)
{
    int     token_count;
    t_disc  *disc;
    float   length;
    
    token_count = 0;
    while (tokens[token_count])
        token_count++;
    
    if (token_count != 5)
    {
        printf("Error: Disc definition requires 4 parameters\n");
        exit(1);
    }
    
    if (scene->discs == NULL)
        scene->discs = (t_disc *)malloc(sizeof(t_disc));
    else
        scene->discs = (t_disc *)realloc(scene->discs, 
                         sizeof(t_disc) * (scene->disc_c + 1));
    
    if (!scene->discs)
    {
        printf("Error: Memory allocation failed for disc\n");
        exit(1);
    }
    
    disc = &scene->discs[scene->disc_c];
    disc->type = 6;
    disc->center = parse_xyz(tokens[1]);
    disc->normal = parse_xyz(tokens[2]);
    disc->radius = ft_atof(tokens[3]);
    disc->colour = parse_rgb(tokens[4]);
    
    length = sqrt(disc->normal.x * disc->normal.x + 
                       disc->normal.y * disc->normal.y + 
                       disc->normal.z * disc->normal.z);
    
    if (length == 0)
    {
        printf("Error: Disc normal vector cannot be zero\n");
        exit(1);
    }
    
    disc->normal.x /= length;
    disc->normal.y /= length;
    disc->normal.z /= length;
    
    if (disc->radius <= 0)
    {
        printf("Error: Disc radius must be positive\n");
        exit(1);
    }
}

void parse_shape(char **tokens, t_scene_data *scene)
{
  if (ft_strncmp(tokens[0], "cy", ft_strlen("cy") + 1) == 0)
  {
    parse_cylinder(tokens, scene);
    scene->cylinder_c++;
  }
  else if (ft_strncmp(tokens[0], "sp", ft_strlen("sp") + 1) == 0)
  {
    parse_sphere(tokens, scene);
    scene->sphere_c++;
  }
  else if (ft_strncmp(tokens[0], "pl", ft_strlen("pl") + 1) == 0)
  {
    parse_plane(tokens, scene);
    scene->plane_c++;
  }
  else if (ft_strncmp(tokens[0], "co", ft_strlen("co") + 1) == 0)
  {
    parse_cone(tokens, scene);
    scene->cone_c++;
  }
  else if (ft_strncmp(tokens[0], "tr", ft_strlen("tr") + 1) == 0)
  {
    parse_triangle(tokens, scene);
    scene->triangle_c++;
  }
  else if (ft_strncmp(tokens[0], "di", ft_strlen("di") + 1) == 0)
  {
    parse_disc(tokens, scene);
    scene->disc_c++;
  }
}
