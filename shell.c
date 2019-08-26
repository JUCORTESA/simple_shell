#include "holberton.h"
/**
 * main - execute a simple shell
 * Return: nothing
 */
int main(void)
{
	char *buffer, **buff = NULL, *path, *cpath;
	ssize_t d = 0;
	size_t bufsize = 1024;
	int status, s;

	path = get_env();
	while(1)
	{
		cpath = cpstring(path);
		signal(SIGINT, sigintHandler);
		prompt();
		buffer = _calloc(bufsize, sizeof(char));
		if (buffer == NULL)
		{
			free(buffer);
			return(0);
		}
		d = getline1(&buffer,&bufsize,stdin);
		if (d == -1)
			exit(0);
		spaces(buffer);
		buffer = compare_path(buffer, cpath);
		buff = getargs(buffer);
		if (buff == NULL)
		{
			free(buffer);
			freeAll(buff);
			return(0);
		}
		if (buff[0] != NULL)
			s = coincidence(buff, buffer);
		if (s == -1 && fork() == 0)
		{
			status = execve(buff[0], buff, NULL);
			if (status == -1 && buff[0 != NULL])
				printf("%s: not found\n", buff[0]);
			freeAll(buff);
			free(buffer);
			exit(0);
		}
		else
			wait(NULL);
		freeAll(buff);
		free(buffer);
	}
	return (0);
}
