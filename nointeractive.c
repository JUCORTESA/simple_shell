#include "holberton.h"
char **noninter(int ac, char *av[])
{
	char **buff;
	int i = 1, y = 0, z, len;

	if (ac != 1)
	{
		buff = malloc(sizeof(char *) * (ac));
		if (!buff)
			return (NULL);
		while(i < ac)
		{
			len = strlen(av[i]);
			buff[y] = malloc(sizeof(char) * (len + 1));
			for(z = 0; z < len; z++)
			{
				buff[y][z] = av[i][z];
			}
			i++;
			y++;
		}
		buff[y] = NULL;
		return (buff);
	}
	return (NULL);
}
