#include "holberton.h"
/**
 * getargs - create a arrays of pointer with all the arguments
 * @buffer: data catched for the getline
 * Return: a duble poirnte to the buffer
 */
char **getargs(char *buffer)
{
	char **buff, *token;
	size_t cont = 0, i, y = 0;

	buff = malloc(sizeof(char *) * (cont + 1));
	if (!buff)
	{
		free(buff);
		return (0); /* pendiente mirar error */
	}
	token = _strtok(buffer, " ");
	while (token != NULL)
	{
		buff[y] = malloc(sizeof(char) * (strlen(token) + 1));
		for (i = 0; i <= (strlen(token) - 1); i++)
			buff[y][i] = token[i];
		if (buff[y][i - 2] == '\n')
			buff[y][i - 2] = '\0';
		else
			buff[y][i] = '\0';
		y++;
		token = _strtok(NULL, " ");
	}
	buff[y] = NULL;
	return (buff);

}
