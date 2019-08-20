#include "holberton.h"
int main(void)
{
	char *buffer, **buff;
	size_t c;
	size_t *p = &c;
        pid_t child_pid;
	int e;

	signal(SIGINT, sigintHandler);
start:
	buffer = NULL;
	c = 0;
	prompt();
	buffer = _getline(p);
	buff =_strtok(buffer);
	e = 0;
	child_pid = fork();
	if (child_pid == 0)
	{

		e = execve(buff[0], buff, NULL);
		exit(0);

	}
	else
		wait(NULL);
	if (e == -1)
		printf("Error.\n");
	goto start;
	return (0);
}
