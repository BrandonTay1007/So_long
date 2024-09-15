/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twei-yo- <twei-yo-@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:36:30 by twei-yo-          #+#    #+#             */
/*   Updated: 2024/09/14 17:00:39 by twei-yo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

void *ft_realloc(void *ptr, size_t size)
{
    void *new_ptr;
    
    if (size == 0) 
    {
        free(ptr);
        return NULL;
    }

    new_ptr = malloc(size);
    if (!new_ptr)
        return (NULL);

    if (ptr) {
        ft_memcpy(new_ptr, ptr, size);
        free(ptr);
    }

    return (new_ptr);
}