/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 01:55:49 by palefebv          #+#    #+#             */
/*   Updated: 2024/11/17 23:41:53 by palefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*extract_line(char **storage)
{
	char	*newline_pos;
	char	*line;
	char	*new_storage;

	newline_pos = ft_strchr(*storage, '\n');
	if (newline_pos)
	{
		line = ft_substr(*storage, 0, newline_pos - *storage + 1);
		new_storage = ft_strdup(newline_pos + 1);
		free(*storage);
		*storage = new_storage;
	}
	else
	{
		line = ft_strdup(*storage);
		free(*storage);
		*storage = NULL;
	}
	return (line);
}

static int	read_buffer(int fd, char **storage)
{
	char	*buffer;
	int		bytes_read;
	char	*temp;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (-1);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(*storage, buffer);
		free(*storage);
		*storage = temp;
	}
	free(buffer);
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = read_buffer(fd, &storage);
	while (bytes_read > 0)
	{
		if (ft_strchr(storage, '\n'))
			break ;
		bytes_read = read_buffer(fd, &storage);
	}
	if (bytes_read == -1 || (bytes_read == 0 && (!storage || !*storage)))
	{
		free(storage);
		storage = NULL;
		return (NULL);
	}
	return (extract_line(&storage));
}

/*
#include <fcntl.h>
#include <stdio.h>
int	main(void)
{
	int	fd;
	
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Erreur lors de l'ouverture du fichier");
		return (1);
	}
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));

	close(fd);
	return (0);
}
*/
/*int	main(int argc, char *argv[])
{
	int	fd;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Erreur lors de l'ouverture du fichier");
		return (1);
	}
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));

	close(fd);
	return (0);
}*/
