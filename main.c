/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twei-yo- <twei-yo-@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 21:48:11 by twei-yo-          #+#    #+#             */
/*   Updated: 2024/09/14 00:30:38 by twei-yo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

int main(int argc, char const *argv[])
{
	char	*map_name;
	int		fd;	
	
	if (argc != 2)
		ft_printf("Error\n");

	map_name = argv[1];
	fd = open(map_name, "O_RDONLY");

}