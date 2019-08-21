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

char *_getline(ssize_t *p);
void prompt(void);
void sigintHandler(int sig_num);
char *_strtok(char *str, const char *delim);
int _strlen(char *s);
char **getargs(char *buffer);
int count(char *buff, char *l);
void freeAll(char *buffer, char **buff);
char **noninter(int ac, char *av[]);

#endif
