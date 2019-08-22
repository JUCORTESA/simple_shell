#include "holberton.h"
/**
 * main - execute a simple shell
 * Return: nothing
 */
int main(int ac, char **av, char **env)
{
	char *buffer, **buff = NULL;
	ssize_t c, flag = 0;
	ssize_t *p = &c;
	pid_t child_pid;
	int i;

	if (ac != 1)
	{
		buff = noninter(ac,av);
		flag = 1;
		goto conti;
	}
//	signal(SIGINT, sigintHandler);
start:
	buffer = NULL;
	c = 0;
	prompt();
	buffer = _getline(p);
	if (buffer == NULL)
		return(0);
	buff = getargs(buffer);
	if (buff == NULL)
		return(0);
conti:
	child_pid = fork();
	if (child_pid == 0)
	{
		execve(buff[0], buff, NULL);
		i = 0;
		while (env[i] != '\0')
		{
			write(STDOUT_FILENO, env[i], strlen(env[i]));
			write(STDOUT_FILENO, "\n", 1);
			i++;
		}
		exit(0);
	}
	else
		wait(NULL);
	freeAll(buffer, buff);
	if (flag)
		exit(0);
	goto start;
	return (0);
}
