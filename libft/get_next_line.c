/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twei-yo- <twei-yo-@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 08:48:10 by twei-yo-          #+#    #+#             */
/*   Updated: 2024/05/24 19:51:56 by twei-yo-         ###   ########.fr       */
/*                                                  	                      */
/* ************************************************************************** */

#include "libft.h"

char	*set_buffer(int fd, char *left_s)
{
	char	*buffer;
	char	*tmp;
	int		b_read;

	b_read = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (b_read != 0 && !ft_strchr(left_s, '\n'))
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		buffer[b_read] = '\0';
		if (!left_s && b_read != 0)
			left_s = ft_strdup("");
		if (left_s)
		{
			tmp = left_s;
			left_s = ft_strjoin(tmp, buffer);
			free(tmp);
		}
	}
	free(buffer);
	return (left_s);
}

char	*set_line(char	*left_s)
{
	int		i;
	char	*line;

	i = 0;
	while (left_s[i] && left_s[i] != '\n')
		i++;
	if (left_s[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	ft_strlcpy(line, left_s, i + 1);
	return (line);
}

char	*trim_left_s(char *left_s)
{
	char	*tmp;
	char	*new_left_s;

	tmp = ft_strchr(left_s, '\n');
	if (tmp == NULL)
	{
		free(left_s);
		return (NULL);
	}
	tmp++;
	if (*tmp == '\0')
	{
		free(left_s);
		return (NULL);
	}
	new_left_s = ft_strdup(tmp);
	free(left_s);
	return (new_left_s);
}

char	*get_next_line(int fd)
{
	static char	*left_s = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	left_s = set_buffer(fd, left_s);
	if (left_s)
		line = set_line(left_s);
	else
	{
		free(left_s);
		line = NULL;
		left_s = NULL;
		return (NULL);
	}
	left_s = trim_left_s(left_s);
	return (line);
}

// int main()
// {
// 	int fd = open("text.txt", O_RDONLY);
// 	char	*a;
// 	int	i = 0;
// 	while (i < 5)
// 	{
// 		a = get_next_line(fd);
// 		printf("[%i]%s\n", i, a);
// 		free(a);
// 		i++;
// 	}
// 	return 0;
// }