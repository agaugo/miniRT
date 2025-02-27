#include "../../includes/minirt.h"

void    init_win(t_data *data)
{
    data->mlx_data.mlx = mlx_init();
    if (!data->mlx_data.mlx)
    {
        printf("Error creating window\n");
        exit(1);
    }
    data->mlx_data.win = mlx_new_window(data->mlx_data.mlx, 800, 600, "miniRT");
    if (!data->mlx_data.win)
    {
        printf("Error creating window\n");
        exit(1);
    }

    mlx_hook(data->mlx_data.win, 2, 1L << 0, handle_key, data);
    mlx_loop(data->mlx_data.win);
}
