#include "../../includes/minirt.h"

int handle_key(int keycode, t_data *data)
{
  if (keycode == 53) //change this for linux at codam
  {
    mlx_destroy_window(data->mlx_data.mlx, data->mlx_data.win);
    exit(0);
  }
  return (1);
}


