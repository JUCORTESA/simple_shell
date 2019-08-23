#include "holberton.h"
/**
 * main - execute a simple shell
 * Return: nothing
 */
int main(void)
{
	char *buffer, **buff = NULL;
	ssize_t d;
	size_t bufsize = 1024;
	int status, s;


	while(1)
	{
		signal(SIGINT, sigintHandler);
		d = 0;
		prompt();
		buffer = malloc(bufsize * sizeof(char));
		if (buffer == NULL)
		{
			free(buffer);
			return(0);
		}
		d = getline(&buffer,&bufsize,stdin);
		if (d == -1)
			exit(0);
		spaces(buffer);
		buff = getargs(buffer);
		if (buff == NULL)
		{
			free(buffer);
			freeAll(buff);
			return(0);
		}
		if (buff[0] != NULL)
			s = coincidence(buff, buffer);
		if (fork() == 0 && s == -1)
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
