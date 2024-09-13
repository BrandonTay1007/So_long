/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twei-yo- <twei-yo-@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 21:48:11 by twei-yo-          #+#    #+#             */
/*   Updated: 2024/09/13 16:49:26 by twei-yo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minilibx-linux/mlx.h"

int main()
{
    void *mlx_connection;
    void *mlx_window;
    mlx_connection = mlx_init();
    mlx_window = mlx_new_window(mlx_connection, 400, 300, "Hello World");
    mlx_loop(mlx_connection);
    mlx_destroy_display(mlx_connection);
}  