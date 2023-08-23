#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
/**
 * main - Simple command line interpreter.
 * @ac : Number of args.
 * @av : Pointer to list of args.
 * @env: List of environment variables.
 * Return: 0 on Success.
 */
int main(int ac __attribute__((unused)), char **av __attribute__((unused))
, char **env)
{
	char *buffer = NULL, *args = NULL, *command[20] = {0};
	size_t len = 0;
	ssize_t bytes = 0;
	int child, stat, flag = 1, exitcode;

	while (flag == 1)
	{
		child = fork();
		if (child == 0)
			execution(bytes, len, args, buffer, command, env);
		if (child != 0)
		{
			wait(&stat);
			exitcode = WEXITSTATUS(stat);
			if (exitcode == 55)
				exit(0);
			if (exitcode != 0)
				exit(exitcode);
		}
	}
	return (0);
}
