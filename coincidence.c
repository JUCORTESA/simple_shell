#include "holberton.h"

int coincidence(char **buff, char *buffer)
{

	data opci[] = {
		{"exit", ext},
		{"env", env},
		{"cd", cd_fun},
		{NULL, NULL}
	};
	int i = 0, j, res = -1, x;
	unsigned int cont = 0;


	while(opci[i].type)
	{
		j = _strlen(buff[0]);
		x = _strlen(opci[i].type);
		cont = 0;
		while(opci[i].type[x] == buff[0][j])
		{
			cont++;
			if (cont == _strlen(opci[i].type))
			{
				res = (*opci[i].functiontype)(buffer, buff);
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
	exit(j % 256);
}
extern char** environ;
int env(char *buff __attribute__((unused)), char **buffer __attribute__((unused)))
{
	size_t i = 0;

	for (; environ[i] != NULL; i++)
	{
		_puts(environ[i]);
		_puts("\n");
	}
	return (1);
}
char *compare_path(char *buffer, char*path)
{
	char *token, *r, *file, *cbuffer, *c;
	int len, d = -1, flag = 0;

	cbuffer = cpstring(buffer);
	r = _strtok(cbuffer, " ");
	len = _strlen(r);
	if(r[len - 1] == '\n')
		r[len - 1] = '\0';
	token = _strtok(path, "/");
	file = str_concat(token, r);
	while(d  == -1)
	{
		free(file);
		if (r[0] != '/')
		{
			token = str_concat(_strtok(NULL, ":"), "/");
			flag = 1;
		}
		else
			token = _strtok(NULL, ":");
		file = str_concat(token, r);
		if( token == NULL || (token[0] == '/' && token[1] == '\0'))
			break;
		d = open(file, O_RDONLY);
		if (d == -1 && flag)
			free(token);
	}
	if (token == NULL || (token[0] == '/' && token[1] == '\0'))
	{
		if (!r[len - 1])
			r[len - 1] = '\n';
		free(path);
		free(cbuffer);
		free(file);
		free(token);
		return(buffer);
	}
	else
	{
		if (buffer[0] != '\n')
		{
			c = str_concat(token, buffer);
			free(buffer);
		}
		free(path);
		free(cbuffer);
		free(file);
		free(token);
		return(c);
	}
}
char *str_concat(char *s1, char *s2)
{
	char *p = NULL;
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
		for (z = 0; z < x; z++)
			p[z] = s1[z];
		for (z = z, c = 0; z < (x + y); z++, c++)
			p[z] = s2[c];
		p[z] = '\0';
		return (p);
	}
	else
		return (p);
}
