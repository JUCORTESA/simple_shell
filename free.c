#include "holberton.h"
/**
 * freeAll - fee al the buf
 * @buf: an arrays of pointers
 * Return: nothing
 */
void freeAll(char **buf)
{
	int i = 0, cont = 0;

	while (buf[i] != NULL)
		cont++, i++;

	if (buf != NULL)
	{
		while (cont >= 0)
		{
			free(buf[cont]);
			cont--;
		}
		free(buf);
	}
}
