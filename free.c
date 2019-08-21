#include "holberton.h"

void freeAll(char *buffer, char **buf)
{
	int i = 0;

	free(buffer);
	if (buf != NULL)
	{
		while (buf[i] != NULL)
			free(buf[i]), i++;
		if (buf[i] == NULL)
			free(buf[i]);
		free(buf);
	}
}
