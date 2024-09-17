/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twei-yo- <twei-yo-@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 11:49:49 by twei-yo-          #+#    #+#             */
/*   Updated: 2024/09/15 23:25:45 by twei-yo-         ###   ########.fr       */
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
		if (ft_arrlen(maps_data->maps[y]) != maps_data->width)
			return (0);   
		y++;
	}
	return (1);
}

int	map_is_closed(t_maps *maps_data)
{
	int x;
	int y;
	
	y = 0;
	x = 0;
	while (maps_data->maps[y][0])
	{
		if (maps_data->maps[y][0] != '1' && 
			maps_data->maps[y][maps_data->width - 1] != '1')
			return (0);
		y++;
	}
	while (maps_data->maps[x][0])
	{
		if (maps_data->maps[x][0] != '1' && 
			maps_data->maps[x][maps_data->height - 1] != '1')
			return (0);
		x++;
	}
	return (1);
}
int valid_char_only(t_maps *maps_data, char *valid_char)
{
	while (maps_data->maps[y])
	{
		x = 0;
		while (maps_data->maps[y][x])
		{
			if (!ft_strchr(valid_char, maps_data->maps[y][x]))
				return (0);	
		}
	}
	return (1);
}

int valid_path(t_maps *maps_data)

{
	int x;
	int y;
	
	x = 0;
	y = 0;
	while (maps_data->maps[y][x])
	{
		
	}
}