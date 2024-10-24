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

// Fonction auxiliaire pour trouver le caractère '\n' dans une chaîne
int	find_newline(char *str)
{
	int i = 0;
	
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

// Fonction auxiliaire pour joindre deux chaînes de caractères
char	*ft_strjoin(char *s1, char *s2)
{
	int		i = 0, j = 0;
	char	*new_str;

	if (!s1 && !s2)
		return (NULL);
	new_str = malloc(sizeof(char) * (strlen(s1) + strlen(s2) + 1));
	if (!new_str)
		return (NULL);
	while (s1 && s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
		new_str[i++] = s2[j++];
	new_str[i] = '\0';
	free(s1);  // Libération mémoire s1
	return (new_str);
}

// Fonction pour extraire la ligne jusqu'à '\n'
char	*extract_line(char **buffer)
{
	int		i;
	char	*line;
	char	*temp;

	i = find_newline(*buffer);
	if (i == -1)  // Pas de '\n' trouvé, toute la chaîne est une ligne
		return (NULL);
	line = strndup(*buffer, i + 1);  // On prend tout jusqu'à '\n'
	temp = strdup(&((*buffer)[i + 1]));  // Le reste est stocké pour l'appel suivant
	free(*buffer);
	*buffer = temp;
	return (line);
}
