#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv) {
	if (argc != 2) {
		printf("Usage: %s <filename>\n", argv[0]);
		return 1;
	}

	int	fd = open(argv[1], O_RDONLY);
	if (fd == -1) {
		perror("Erreur lors de l'ouverture du fichier");
		return 1;
	}

	char	*line;
	while ((line = get_next_line(fd)) != NULL) {
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	printf("Fin de la lecture du fichier.\n");
	return 0;
}
