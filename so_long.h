/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twei-yo- <twei-yo-@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:03:33 by twei-yo-          #+#    #+#             */
/*   Updated: 2024/09/23 13:08:26 by twei-yo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SO_LONG_H
#define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "libft/libft.h"

typedef struct s_maps {
    
    char    **maps;
    int     height;
    int     width;
    int     collectible_count;
    int     *player_pos;
    int     *exit_pos;

} t_maps;

t_maps *get_map_data(int fd);
int	map_is_rectangular(t_maps *maps_data);
int	map_is_closed(t_maps *maps_data);
int valid_char_only(char **maps, char *valid_char);
int find_valid_path(t_maps *maps_data);

# endif