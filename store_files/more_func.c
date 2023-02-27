#include "shell.h"

/**
 * _putchar - writes character to stdout
 * @c: Character to print
 *
 * Return: 1 on success
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strcmp - Compares two strings
 * @s1: First string
 * @s2: Second string
 *
 * Return: int value
 */

int _strcmp(char *s1, char *s2)
{
	int len_1 = 0, len_2 = 0;
	int pos = 0, diff = 0;
	int lim = 0;

	len_1 = _strlen(s1);
	len_2 = _strlen(s2);

	if (len_1 <= len_2)
		lim = len_1;
	else
		lim = len_2;

	while (pos <= lim)
	{
		if (s1[pos] == s2[pos])
		{
			pos++;
			continue;
		}
		else
		{
			diff = s1[pos] - s2[pos];
			break;
		}
		pos++;
	}
	return (diff);
}

/**
 * _strlen - counts the length of the string
 * @s: the string to count
 *
 * Return: Length of the string
 */

int _strlen(const char *s)
{
	int i = 0;

	while (s[i])
		i++;

	return (i);
}

/**
 * _strcat - Concatenates two strings
 * @dest: The destination string
 * @src: The source string
 *
 * Return: A pointer to the destination string
 */
char *_strcat(char *dest, char *src)
{
	int str = 0, i = 0;

	while (dest[str])
		str++;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[str] = src[i];
		str++;
	}

	dest[str] = '\0';
	return (dest);
}

/**
 * _strdup - Duplicate a string
 * @s: the string to be duplicated
 *
 * Return: the duplicated string
 */
char *_strdup(char *s)
{
	int val = 0, length = 1;
	char *dupStr;

	if (s == NULL)
		return (NULL);

	length = _strlen(s);
	dupStr = malloc((sizeof(char) * length) + 1);
	if (dupStr == NULL)
		return (NULL);

	while (val < length)
	{
		dupStr[val] = s[val];
		val++;
	}

	dupStr[val] = '\0';
	return (dupStr);
}
