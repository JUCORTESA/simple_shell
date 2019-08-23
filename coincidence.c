#include "holberton.h"

int coincidence(char **buff, char *buffer)
{

	data opci[] = {
		{"exit", ext},
		{NULL, NULL}
	};
	int i = 0, j, res = -1;
	unsigned int cont = 0;

	while(opci[i].type)
	{
		j = 0;
		while(opci[i].type[j] == buff[0][j])
		{
			cont++;
			if (cont == strlen(buff[0]))
			{
				res = 1;
				(*opci[i].functiontype)(buffer, buff);
			}
			j++;
		}
		i++;
	}
	return (res);
}
int ext(char *buff, char **buffer)
{
	int i = 0, j = 0, dec = 0;

	if (buffer[1])
	{
		while(buffer[1][i] != '\0')
		{
			j = (j * dec) + (buffer[1][i] - '0');
			dec = 10;
			i++;
		}
	}
	free(buff);
	freeAll(buffer);
	exit(j);
}
