#include "holberton.h"
/**
 * main - execute a simple shell
 * Return: nothing
 */
int main(void)
{
	char *buffer = NULL, **buff = NULL, *path, *cpath;
	ssize_t d = 0;
	size_t bufsize = 1024;
	int status, s = 5, cont = 0, e;

	while (1)
	{
		cont++, path = get_env("PATH="), cpath = cpstring(path);
		signal(SIGINT, sigintHandler), prompt();
		buffer = malloc(bufsize * sizeof(char));
		if (buffer == NULL)
			free(buffer), ret();
		d = getline1(&buffer, &bufsize, stdin);
		if (d == -1)
			exit(0);
		spaces(buffer), buffer = compare_path(buffer, cpath);
		if (buffer[0] != '\n' && buffer[0] != '\0')
		{
			buff = getargs(buffer);
			if (buff == NULL)
				free(buffer), freeAll(buff), ret();
			if (buff[0] != NULL)
				s = coincidence(buff, buffer);
		}
		if (s == -1 && buff[0] != NULL && fork() == 0)
		{
			status = execve(buff[0], buff, NULL);
			if (status == -1 && buff[0] != NULL)
				printf("hsh: %i: %s: not found\n", cont, buff[0]);
			freeAll(buff), free(buffer), ret();
		}
		else
		{
			wait(&e);
			extstatus(&e);
		}
		if (s == 0 && buff[0][0] != '\n')
			printf("hsh: cd: %s: No such file or directory\n", buff[1]);
		if (s == 3 && buff[0][0] != '\n')
			printf("hsh: exit: Illegal number: %s\n", buff[1]);
		if (buffer[0] != '\n' && buffer[0] != '\0')
			freeAll(buff);
		free(buffer);
	}
	return (0);
}
/**
 * ret - return function
 *return: nothing
 */
void ret(void)
{
	exit(0);
}
/**
 * status - function
 *return: nothing
 */
int extstatus(int *p)
{
	static int status;

	if(p != NULL)
		status = *p;
	return (status);
}
