#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * _getenv - function to get environment.
 * @name: name of the global variable.
 * Return: path handled
 */
char *_getenv(const char *name)
{
	int i, j;
	char *value;

	if (!name)
		return (NULL);
	for (i = 0; env[i]; i++)
	{
		j = 0;
		if (name[j] == env[i][j])
		{
			while (name[j])
			{
				if (name[j] != env[i][j])
					break;

				j++;
			}
			if (name[j] == '\0')
			{
				value = (env[i] + j + 1);
				return (value);
			}
		}
	}
	return (0);
}
void Path() 
{
 
    char* path = _getenv("PATH");
    
    if (path == NULL)
    {
        printf("NULL.\n");
        return;
    }

    char* token = _strtok(path, ":");
    
    while (token != NULL) {
        printf("%s\n", token);
        token = _strtok(NULL, ":");
    }
}
