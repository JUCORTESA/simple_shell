#include "holberton.h"

void freeAll(char **buf)
{
	int i = 0;

	if (buf != NULL)
	{
		while (buf[i] != NULL)
			free(buf[i]), i++;
		if (buf[i] == NULL)
			free(buf[i]);
		free(buf);
	}
}
