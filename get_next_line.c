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

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*line;
	char		*tmp_buf;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp_buf = malloc(BUFFER_SIZE + 1);
	if (!tmp_buf)
		return (NULL);
	while ((find_newline(buffer) == -1) && (bytes_read = read(fd, tmp_buf, BUFFER_SIZE)) > 0)
	{
		tmp_buf[bytes_read] = '\0';
		buffer = ft_strjoin(buffer, tmp_buf);
	}
	free(tmp_buf);
	if (bytes_read < 0)
		return (NULL);
	line = extract_line(&buffer);
	if (!line && buffer)
	{
		line = strdup(buffer);
		free(buffer);
		buffer = NULL;
	}
	return (line);
}
