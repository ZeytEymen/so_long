#include "so_long.h"

int	main(int ac, char **av)
{
	t_mlx	solong;

	(void) ac;
	solong.mlx = mlx_init();
	load_images(&solong);
	name_ber(av[1]);
	solong.map_path = av[1];
	solong.map = getmap(solong.map_path);
}
