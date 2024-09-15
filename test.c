int main(int argc, char const *argv[])
{
	int fd = open("maps/map1.ber", O_RDONLY);
	char **maps = extract_map(fd);
	
	// Test case for get_char_pos
	printf("Testing get_char_pos function:\n");
	
	// Test case 1: Find 'P' (player) position
	int *player_pos = get_char_pos(maps, 'P');
	if (player_pos)
		printf("Player position: (%d, %d)\n", player_pos[0], player_pos[1]);
	else
		printf("Player not found in the map\n");
	
	// Test case 2: Find 'E' (exit) position
	int *exit_pos = get_char_pos(maps, 'E');
	if (exit_pos)
		printf("Exit position: (%d, %d)\n", exit_pos[0], exit_pos[1]);
	else
		printf("Exit not found in the map\n");
	
	// Test case 3: Find a character that doesn't exist
	int *nonexistent_pos = get_char_pos(maps, 'Z');
	if (nonexistent_pos)
		printf("Unexpected: Found position for 'Z': (%d, %d)\n", nonexistent_pos[0], nonexistent_pos[1]);
	else
		printf("As expected, 'Z' not found in the map\n");
	
	// Free the memory allocated by get_char_pos
	free(player_pos);
	free(exit_pos);
	free(nonexistent_pos);
	// Clean up
	int i = 0;
	free(maps);
	close(fd);
	return 0;
}