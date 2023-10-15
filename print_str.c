#include "main.h"
/**
 * pt_str - Prints a string
 * @a: the given string
 * @len: the given length
 *
 * Return: number of chars printed
*/
int pt_str(va_list a, int len)
{
	int i;
	char *s = va_arg(a, char *);
	char *ns = "(null)";

	if (s != NULL)
	{
		for (i = 0; s[i] != '\0'; i++)
		{
			_putchar(s[i]);
			len++;
		}
	}
	else
	{
		for (i = 0; ns[i] != '\0'; i++)
		{
			_putchar(ns[i]);
			len++;
		}
	}
	return (len);
}
