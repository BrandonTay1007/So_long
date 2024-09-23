/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twei-yo- <twei-yo-@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 11:49:49 by twei-yo-          #+#    #+#             */
/*   Updated: 2024/09/23 22:49:42 by twei-yo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_is_rectangular(t_maps *maps_data)
{
	int x;
	int y;
	
	y = 0;
	while (maps_data->maps[y])
	{		
		if (ft_strlen(maps_data->maps[y]) != maps_data->width)
			return (0);
		y++;
	}
	return (1);
}

int	map_is_closed(t_maps *maps_data)
{
	int	x;
	int	y;

	x = 0;
	while (x < maps_data->width)
	{
		if (maps_data->maps[0][x] != '1' || 
		maps_data->maps[maps_data->height - 1][x] != '1')
			return (0);
		x++;
	}

	y = 0;
	while (y < maps_data->height)
	{
		if (maps_data->maps[y][0] != '1' || maps_data->maps[y][maps_data->width - 1] != '1')
			return (0);
		y++;
	}

	return (1);
}

int valid_char_only(char **maps, char *valid_char)
{
	int	x;
	int y;

	y = 0;
	while (maps[y])
	{
		x = 0;
		while (maps[y][x])
		{
			if (!ft_strchr(valid_char, maps[y][x]))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

char **flood_fill(char **maps, int x, int y, t_maps *maps_data, int *collectible_count)
{	
	if (x < 0 || x >= maps_data->width || y < 0 || y >= maps_data->height || !maps[y][x] || maps[y][x] == '1')
		return (maps);
	else
	{
		if (maps[y][x] == 'C')
			(*collectible_count)--;
		maps[y][x] = '1';
		maps = flood_fill(maps, x + 1, y, maps_data, collectible_count);
		maps = flood_fill(maps, x - 1, y, maps_data, collectible_count);
		maps = flood_fill(maps, x, y + 1, maps_data, collectible_count);
		maps = flood_fill(maps, x, y - 1, maps_data, collectible_count);
	}
	return (maps);
}

int find_valid_path(t_maps *maps_data)
{
	char	**dup_maps;
	int		collectible_count;

	collectible_count = maps_data->collectible_count;
	dup_maps = ft_arrdup(maps_data->maps);
	flood_fill(dup_maps, maps_data->player_pos[0], maps_data->player_pos[1], maps_data, &collectible_count);
	
	if (collectible_count == 0)
		return (1);
	else
		return (0);
}