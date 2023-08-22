#include "main.h"
/**
 * _atoi - Convert string to int.
 * @s : pointer to string.
 * Return: integer.
 */
int _atoi(char *s)
{
	int j = 0, i = 0;
	int k = 0;
	int minus_count = 0;
	int track_last_digit = 0;
	int number = 0;
	int num = 0;

	while (*(s + i) != '\0')
	{
		if (!(*(s + i) <= 57 && *(s + i) >= 48))
			return (-1);
		i++;
	}
	while (!((int)*(s + j) <= 57 && (int)*(s + j) >= 48) && *(s + j) != '\0')
	{
		if ((int)*(s + j) == 45)
			minus_count += 1;
		j++;
	}
	while (*(s + k) != '\0')
	{
		if ((int)*(s + k) <= 57 && (int)*(s + k) >= 48)
		{
			num = (int)*(s + k) - 48;
			if (minus_count % 2 != 0)
				num = -1 * ((int)*(s + k) - 48);
			number = number * 10 + num;
			if (track_last_digit != 1)
				track_last_digit = 1;
		}
		else if (track_last_digit == 1)
			break;
		k++;
	}
	return (number);
}
