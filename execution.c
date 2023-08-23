#include "main.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * execution - Executes a command within the child process.
 * @bytes : The variable that stores the number of bytes of getline().
 * @len : Length of input.
 * @args : Array of arguments.
 * @buffer : Buffer where the input is stored.
 * @command : Array where the commands are stored.
 * @environment : The array that holds environment variables.
 * Return: Void.
 */
void execution(ssize_t bytes, size_t len, char *args, char *buffer
, char *command[], char **environment)
{
	int i = 1;

	write(1, "$ ", 2);
	bytes = getline(&buffer, &len, stdin);
	buffer[bytes - 1] = '\0';
	args = strtok(buffer, " ");
	command[0] = args;
	command[6] = "/usr/";
	while (args != NULL)
	{
		args = strtok(NULL, " ");
		command[i] = args;
		i++;
	}
	if (_strcmp(command[0], "exit") == 0 && !command[1])
		exit(55);
	if (_strcmp(command[0], "exit") == 0 && command[1] != NULL)
		exit(_atoi(command[1]));
	if (_strcmp(command[0], "env") == 0)
		while (environment != NULL)
		{
			printf("%s\n", *environment);
			environment++;
		}
	if (bytes == -1)
		perror("Error:");
	if (execve(command[0], command, environment) == -1)
		perror("./hsh");
}
