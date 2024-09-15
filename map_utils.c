/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twei-yo- <twei-yo-@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 22:23:19 by twei-yo-          #+#    #+#             */
/*   Updated: 2024/09/15 12:32:46 by twei-yo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**extract_map(int fd)
{
	char	*cur_line;
	char	**map;
	char	*map_content;
	char	*temp;

	map_content = ft_strdup("");
	while (1)
	{
		cur_line = get_next_line(fd);
		if (cur_line == NULL)
			break ;
		temp = ft_strjoin(map_content, cur_line);
		free(map_content);
		free(cur_line);
		map_content = temp;
	}
	map = ft_split(map_content, '\n');
	free(map_content);
	return (map);
}

static int	get_char_data(char **maps, char c, int max)
{
	int	y;
	int	x;
	int count;
	
	y = 0;
	count = 0;

	while (maps[y])
	{
		x = 0;
		while (maps[y][x])   
		{
			if (maps[y][x] == c)
			{
				count++;
				if (max != -1 && count > max)
					return -1;
			}
			x++;
		}
		y++;
	}
	return count;
}
int *get_char_pos(char **maps, char c)
{
	int y;
	int x;
	int *pos;

	pos = malloc(sizeof(int) * 2);
	if (!pos)
		return (NULL);
	y = 0;
	while (maps[y])
	{
		x = 0;
		while (maps[y][x])
		{
			if (maps[y][x] == c)
			{
				pos[0] = x;
				pos[1] = y;
				return (pos);
			}
			x++;
		}
		y++;
	}
	free(pos);
	return (NULL);
}

t_maps *get_map_data(int fd)
{
	t_maps	*maps_data;
	maps_data = malloc(sizeof(*maps_data));
	if (!maps_data)
		return (NULL);
	maps_data->maps = extract_map(fd);
	if (!maps_data->maps)
	{
		free(maps_data);
		return (NULL);
	}

	maps_data->height = ft_arrlen(maps_data->maps);
	maps_data->width = ft_strlen(maps_data->maps[0]);
	maps_data->player_pos = get_char_pos(maps_data->maps, 'P');
	maps_data->exit_pos = get_char_pos(maps_data->maps, 'E');
	maps_data->collectible_count = get_char_data(maps_data->maps, 'C', -1);
	// if (!validate_map_data(maps_data))
	// {
	// 	free_map_data(maps_data);
	// 	return (NULL);
	// }
	return (maps_data);
}

int main()
{
	int fd = open("maps/map1.ber", O_RDONLY);
	t_maps *maps_data = get_map_data(fd);
	printf("height: %d\n", maps_data->height);
	printf("width: %d\n", maps_data->width);
	printf("player_pos: %d %d\n", maps_data->player_pos[0],maps_data->player_pos[1]);
	printf("exit_pos: %d %d\n", maps_data->exit_pos[0],maps_data->exit_pos[1]);
	printf("collectible_count: %d\n", maps_data->collectible_count);
}