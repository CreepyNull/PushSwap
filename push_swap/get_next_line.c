/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylamgha <aylamgha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 09:14:48 by aylamgha          #+#    #+#             */
/*   Updated: 2024/08/19 16:48:26 by aylamgha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

char	*new_lines(char *read_lines)
{
	int		i;
	int		j;
	char	*new_lines;

	i = 0;
	while (read_lines[i] && read_lines[i] != '\n')
		i++;
	if (!read_lines[i])
	{
		free(read_lines);
		return (NULL);
	}
	new_lines = (char *)malloc(sizeof(char) * (ft_strlen(read_lines) - i + 1));
	if (!new_lines)
		return (NULL);
	i++;
	j = 0;
	while (read_lines[i])
		new_lines[j++] = read_lines[i++];
	new_lines[j] = '\0';
	free(read_lines);
	return (new_lines);
}

char	*lines(char *read_lines)
{
	char	*lines;
	int		i;

	i = 0;
	if (!read_lines[i])
		return (NULL);
	while (read_lines[i] && read_lines[i] != '\n')
		i++;
	lines = (char *)malloc(sizeof(char) * i + 2);
	if (!lines)
		return (NULL);
	i = 0;
	while (read_lines[i] && read_lines[i] != '\n')
	{
		lines[i] = read_lines[i];
		i++;
	}
	if (read_lines[i] == '\n')
	{
		lines[i] = read_lines[i];
		i++;
	}
	lines[i] = '\0';
	return (lines);
}

char	*read_lines(int fd, char *read_lines)
{
	char	*buffer;
	int		r;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	r = 1;
	while (!ft_strchr(read_lines, '\n') && r != 0)
	{
		r = read(fd, buffer, BUFFER_SIZE);
		if (r == -1)
		{
			free(buffer);
			if (read_lines)
				free(read_lines);
			return (NULL);
		}
		buffer[r] = '\0';
		read_lines = ft_strjoin(read_lines, buffer);
	}
	free(buffer);
	return (read_lines);
}

char	*get_next_line(int fd)
{
	static char	*reading_lines;
	char		*get_lines;

	if (fd == -1)
		free(reading_lines);
	if (BUFFER_SIZE <= 0 || fd < 0 || BUFFER_SIZE >= 2147483647)
		return (0);
	reading_lines = read_lines(fd, reading_lines);
	if (!reading_lines)
		return (NULL);
	get_lines = lines(reading_lines);
	reading_lines = new_lines(reading_lines);
	return (get_lines);
}
