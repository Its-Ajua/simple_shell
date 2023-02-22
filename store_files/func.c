#include "shell.h"

/**
 * _puts - Prints a string
 * @s: The string to print
 *
 * Return: Nothing to returns
 */
void _puts(char *s)
{
	while (*s)
	{
		_putchar(*s);
		s++;
	}

	_putchar('\n');
}

/**
 * _strncmp - Compares at most the first n bytes of str1 and str2
 * @s1: The first string
 * @s2: The second string
 * @length: The limit bytes of comparison
 *
 * Return: int value
 */
int _strncmp(const char *s1, const char *s2, size_t length)
{
	unsigned int i = 0;
	int j = 0;

	while (i < length)
	{
		if (s1[i] == s2[j])
		{
			i++;
			continue;
		}
		else
		{
			j = s1[i] - s2[i];
			break;
		}

		i++;
	}

	return (j);
}

/**
 * _realloc - Resize the pointer that was previously allocated
 * @ptr: The pointer previously allocated
 * @old_size: The old size of the pointer
 * @new_size: The new size of the new pointer
 *
 * Return: A new pointer to the memory block allocated with the new size
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *val;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		val = malloc(new_size);

		if (val == NULL)
			return (NULL);

		return (val);
	}
	else
	{
		if (new_size == 0)
		{
			free(ptr);
			return (NULL);
		}
	}

	val = malloc(new_size);

	if (val == NULL)
		return (NULL);

	for (i = 0; i < old_size && i < new_size; i++)
	{
		val[i] = ((char *) ptr)[i];
	}

	free(ptr);
	return (val);
}

/**
 * _atoi - Convert a string to an integer.
 * @s: The pointer to convert
 *
 * Return: A integer
 */
int _atoi(char *s)
{
	int x = 1, y = 0, z = 0;
	unsigned int val = 0;

	while (s[z])
	{
		if (s[z] == '-')
			x *= -1;

		while (s[z] >= '0' && s[z] <= '9')
		{
			y = 1;
			val = (val * 10) + (s[z] - '0');
			z++;
		}

		if (y == 1)
			break;

		z++;
	}

	val *= x;
	return (val);
}
