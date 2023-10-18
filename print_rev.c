#include "main.h"
/**
 * pt_rev - Prints the reversed string
 * @a: the given string
 * @len: the previous length
 *
 * Return: number of digits printed
*/
int pt_rev(va_list a, int len)
{
	int i;
	char *str;

	str = va_arg(a, char *);

	if (str != NULL)
	{
		i = 0;

		while (str[i] != '\0')
		{
			i++;
		}
		i--;

		while (i >= 0)
		{
			_putchar(str[i]);
			len++;
			i--;
		}
	}
	else
	{
		str = "(null)";
		for (i = 5; i >= 0 ; i--)
		{
			_putchar(str[i]);
			len++;
		}
	}
	return (len);
}
