#include "main.h"
/**
 * _strcmp - Compare two strings.
 * @s1 : pointer to first string.
 * @s2 : pointer to second string.
 * Return: Integer; result of ASCII soustraction.
 */
int _strcmp(char *s1, char *s2)
{
	int i;
	int difference = 0;
	int len_max = _strlen(s1);

	if (_strlen(s2) > len_max)
		len_max = _strlen(s2);
	for (i = 0; i < len_max; i++)
	{
		difference += *(s1 + i) - *(s2 + i);
		if (difference != 0)
			return (difference);
	}
	return (difference);
}
