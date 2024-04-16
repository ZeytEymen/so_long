#include "so_long.h"

void load_images(t_mlx *map)
{
    int width;
    int height;

    map -> bird = mlx_xpm_file_to_image(map -> mlx, "textures/bird.xpm", &width, &height);
    map -> grass = mlx_xpm_file_to_image(map -> mlx, "textures/grass.xpm", &width, &height);
    map -> nest= mlx_xpm_file_to_image(map -> mlx, "textures/nest.xpm", &width, &height);
    map -> wall = mlx_xpm_file_to_image(map -> mlx, "textures/wall.xpm", &width, &height);
    map -> worm = mlx_xpm_file_to_image(map -> mlx, "textures/worm.xpm", &width, &height);
}