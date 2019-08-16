#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(void)
{
	char *buffer = NULL;
	size_t bufsize = 0, cont = 0, i;
	ssize_t c;
	char **buff;
	char *token;
	char *pal;


	printf("New shell$ ");
	c = getline(&buffer, &bufsize, stdin);
	token = strtok(buffer, " ");
	while (token != NULL)
		cont++, token = strtok(NULL, " ");
	buff = malloc(sizeof(char *) * (cont + 1));
	if (!buff)
		return (0);
	pal = strtok(buffer, " ");
	buff[0] = malloc(sizeof(char) * (strlen(pal) + 1));
	for(i = 0; i < (strlen(pal) -1); i++)
		buff[0][i] = pal[i];
	buff[0][i] = '\0';
	buff[1] = NULL;
	execve(buff[0], buff, NULL);

	return (0);
}
