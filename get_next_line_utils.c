/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 01:55:18 by palefebv          #+#    #+#             */
/*   Updated: 2024/10/25 01:55:29 by palefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s) {
	size_t	len = 0;
	while (s[len])
		len++;
	return len;
}

char	*ft_strcpy(char *dest, const char *src) {
	char	*d = dest;
	while ((*d++ = *src++));
	return dest;
}

char	*ft_strjoin(char *s1, char *s2) {
	if (!s1 && !s2)
		return NULL;
	if (!s1)
		return ft_strdup(s2);
	if (!s2)
		return ft_strdup(s1);
	char	*joined = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!joined)
		return NULL;
	ft_strcpy(joined, s1);
	ft_strcpy(joined + ft_strlen(s1), s2);
	free(s1);
	return joined;
}

char	*ft_strchr(const char *s, int c) {
	while (*s) {
		if (*s == (char)c)
			return (char *)s;
		s++;
	}
	if (c == '\0')
		return (char *)s;
	return NULL;
}

char	*ft_strdup(const char *s) {
	char	*dup = malloc(ft_strlen(s) + 1);
	if (!dup)
		return NULL;
	ft_strcpy(dup, s);
	return dup;
}
