#include "holberton.h"
char **_strtok(char *buffer)
{
	char **buff, *token;
	size_t cont = 0, i;

	token = strtok(buffer, " ");
	while (token != NULL)
		cont++, token = strtok(NULL, " ");
	buff = malloc(sizeof(char *) * (cont + 1));
	if (!buff)
		return (0);
	token = strtok(buffer, " ");
	buff[0] = malloc(sizeof(char) * (strlen(token) + 1));
	for(i = 0; i < (strlen(token) -1); i++)
		buff[0][i] = token[i];
	buff[0][i] = '\0';
	buff[1] = NULL;
	return (buff);

}
