#ifndef SHELL_H
#define SHELL_H


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/stat.h>
#include <stdint.h>
#include <stdarg.h>


void prompt(void);
void sigintHandler(int sig_num);
char *_strtok(char *str, const char *delim);
int _strlen(char *s);
char **getargs(char *buffer);
int count(char *buff, char *l);
void freeAll(char **buff);
/**
 * struct type - struct of type of data
 * @type: type od data
 * @functiontype: pointer to de function
 */
typedef struct type
{
	char *type;
	int (*functiontype)();
} data;


#endif
