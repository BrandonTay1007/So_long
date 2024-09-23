#include "so_long.h"

int main(int argc, char const *argv[])
{
	int fd = open("maps/map1.ber", O_RDONLY);
	
	t_maps *maps_data = get_map_data(fd);
	printf("height: %d\n", maps_data->height);
	printf("width: %d\n", maps_data->width);
	printf("player_pos: %d %d\n", maps_data->player_pos[0],maps_data->player_pos[1]);
	printf("exit_pos: %d %d\n", maps_data->exit_pos[0],maps_data->exit_pos[1]);
	printf("collectible_count: %d\n", maps_data->collectible_count);
	
	printf("valid_char_only: %d\n", valid_char_only(maps_data->maps, "01PCE"));
	printf("is_rectangular: %d\n", map_is_rectangular(maps_data));
	printf("is_closed: %d\n", map_is_closed(maps_data));
	printf("find_valid_path: %d\n", find_valid_path(maps_data));
}