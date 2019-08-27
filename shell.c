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
	int status, s = 0, cont = 0;

	while (1)
	{
		cont++, path = get_env("PATH="), cpath = cpstring(path);
		signal(SIGINT, sigintHandler), prompt();
		buffer = malloc(bufsize * sizeof(char));
		if (buffer == NULL)
		{
			free(buffer);
			return (0);
		}
		d = getline1(&buffer, &bufsize, stdin);
		if (d == -1)
			exit(0);
		spaces(buffer), buffer = compare_path(buffer, cpath), buff = getargs(buffer);
		if (buff == NULL)
		{
			free(buffer), freeAll(buff);
			return (0);
		}
		if (buff[0] != NULL)
			s = coincidence(buff, buffer);
		if (s == -1 && buff[0] != NULL && fork() == 0)
		{
			status = execve(buff[0], buff, NULL);
			if (status == -1 && buff[0] != NULL)
				printf("hsh : %i: %s: not found\n", cont, buff[0]);
			freeAll(buff), free(buffer);
			exit(0);
		}
		if (s == 0)
			printf("hsh : cd: %s: No such file or directory\n", buff[1]);
		else
			wait(NULL);
		free(buffer);
		freeAll(buff);
	}
	return (0);
}
