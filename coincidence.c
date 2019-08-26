#include "holberton.h"

int coincidence(char **buff, char *buffer)
{

	data opci[] = {
		{"exit", ext},
		{"env", env},
		{NULL, NULL}
	};
	int i = 0, j, res = -1, x;
	unsigned int cont = 0;


	while(opci[i].type)
	{
		j = strlen(buff[0]);
		x = strlen(opci[i].type);
		cont = 0;
		while(opci[i].type[x] == buff[0][j])
		{
			cont++;
			if (cont == strlen(opci[i].type))
			{
				res = 1;
				(*opci[i].functiontype)(buffer, buff);
			}
			j--;
			x--;
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
extern char** environ;
int env(char *buff __attribute__((unused)), char **buffer __attribute__((unused)))
{
	size_t i = 0;

	for (; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
	}
	return (0);
}
char *compare_path(char *buffer, char*path)
{
	char *token, *r, *file, *cbuffer;
	int len;

	cbuffer = cpstring(buffer);
	r = _strtok(cbuffer, " ");
	len = strlen(r);
	if(r[len - 1] == '\n')
		r[len - 1] = '\0';
	token = _strtok(path, "/");
	file = str_concat(token, r);
	while(open(file, O_RDONLY) == -1)
	{
		if (r[0] != '/')
			token = str_concat(_strtok(NULL, ":"), "/");
		else
			token = _strtok(NULL, ":");
		file = str_concat(token, r);
		if( token == NULL || (token[0] == '/' && token[1] == '\0'))
			break;
	}
	if (token == NULL || (token[0] == '/' && token[1] == '\0'))
	{
		if (!r[len - 1])
			r[len - 1] = '\n';
		free(path);
//		free(cbuffer);
//		free(file);
//		free(token);
		return(buffer);
	}
	else
	{
		buffer = str_concat(token, buffer);
		free(path);
		free(cbuffer);
		free(file);
		free(token);
		return(buffer);
	}
}
char *str_concat(char *s1, char *s2)
{
	void *p = NULL;
	char *s;
	int x = 0, y = 0, z, c;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	while (s1[x] != '\0')
		x++;
	while (s2[y] != '\0')
		y++;
	p = malloc(sizeof(char) * ((x + y) + 1));
	if (p != 0)
	{
		s = (char *)p;
		for (z = 0; z < x; z++)
			s[z] = s1[z];
		for (z = z, c = 0; z < (x + y); z++, c++)
			s[z] = s2[c];
		s[z] = '\0';
		return (s);
	}
	else
		return (p);
}
