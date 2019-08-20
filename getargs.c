#include "holberton.h"
/**
 * getargs - create a arrays of pointer with all the arguments
 * @buffer: data catched for the getline
 * Return: a duble poirnte to the buffer
 */

int count(char *buff, char *l)
{
	int i = 0, j = 0;
	if (l != NULL)
	{
		while (buff && buff[i] != '\0')
		{
			if (buff[i] != l[0])
			{
				if (buff[i + 1] == l[0] || buff[i + 1] == '\0')
					j++;
			}
			i++;
		}
	}
	return (j);
}
char **getargs(char *buffer)
{
	char **buff, *token;
	size_t cont = 0, i, y = 0;

	cont = count(buffer, " ");
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
