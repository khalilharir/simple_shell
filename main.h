#ifndef MAIN_H
#define MAIN_H

#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int _strlen(char *s);
int _strcmp(char *s1, char *s2);
int _atoi(char *s);
int execution(ssize_t bytes, size_t len, char *args, char *buffer
, char *command[], char **environment);

#endif
