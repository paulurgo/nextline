/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 01:55:49 by palefebv          #+#    #+#             */
/*   Updated: 2024/10/25 01:56:04 by palefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char **storage) {
	char	*newline_pos = ft_strchr(*storage, '\n');
	char	*line;
	char	*new_storage;

	if (newline_pos) {
		*newline_pos = '\0';
		line = ft_strdup(*storage);
		new_storage = ft_strdup(newline_pos + 1);
		free(*storage);
		*storage = new_storage;
		if (**storage == '\0') {
			free(*storage);
			*storage = NULL;
		}
		return line;
	} else {
		line = ft_strdup(*storage);
		free(*storage);
		*storage = NULL;
		return line;
	}
}

char	*get_next_line(int fd) {
	static char	*storage = NULL;
	char		buffer[BUFFER_SIZE + 1];
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return NULL;
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0) {
		buffer[bytes_read] = '\0';
		storage = ft_strjoin(storage, buffer);
		if (!storage)
			return NULL;
		if (ft_strchr(storage, '\n'))
			break ;
	}
	if (bytes_read == -1)
		return NULL;
	if (storage && *storage)
		return extract_line(&storage);
	return NULL;
}
