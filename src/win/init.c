#include "../../inc/minirt.h"

void    init_win(void)
{
    t_data data;

    data.mlx = mlx_init();
    if (!data.mlx)
    {
        printf("Error creating window\n");
        exit(1);
    }
    data.win = mlx_new_window(data.mlx, 800, 600, "miniRT");
    if (!data.win)
    {
        printf("Error creating window\n");
        exit(1);
    }

    mlx_hook(data.win, 2, 1L << 0, handle_key, &data);
    mlx_loop(data.mlx);
}
