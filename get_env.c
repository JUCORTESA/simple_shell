#include "holberton.h"
extern char** environ;
char *get_env(char *path)
{
	size_t i = 0, j;
	int cont, flag = 0;

	for (; environ[i] != NULL; i++)
	{
		for (j = 0, cont = 0; environ[i][j] == path[j]; ++cont, j++)
		{
			if(cont == 2)
			{
				flag = 1;
				break;
			}
		}
		if (flag)
			break;
	}
	return(environ[i]);
}
char *get_pwd(void)
{
	size_t i = 0, j;
	int cont, flag = 0;
	char *path = "PWD=";

	for (; environ[i] != NULL; i++)
	{
		for (j = 0, cont = 0; environ[i][j] == path[j]; ++cont, j++)
		{
			if(cont == 2)
			{
				flag = 1;
				break;
			}
		}
		if (flag)
			break;
	}
	return(cpstring(environ[i]));
}
