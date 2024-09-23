/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twei-yo- <twei-yo-@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 22:35:21 by twei-yo-          #+#    #+#             */
/*   Updated: 2024/09/23 22:41:17 by twei-yo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char **ft_arrdup(char **arr)
{
    char **new_arr;
    int i;
    
    i = 0;
    new_arr = (char **)malloc(sizeof(char *) * ft_arrlen(arr));
    if (!new_arr)
        return (NULL);
    while (arr[i])
    {
        new_arr[i] = ft_strdup(arr[i]);
        i++;
    }
    new_arr[i] = NULL;
    return (new_arr);
}