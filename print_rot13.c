#include "main.h"
/**
 * pt_rot13 - Prints the rot13'ed string
 * @a: the given string
 * @len: the previous length
 *
 * Return: number of digits printed
*/
int pt_rot13(va_list a, int len)
{
	char *s = va_arg(a, char *);
	int i, d;
	char l, f;

	if (s == NULL)
		s = "(null)";

	for (i = 0; s[i] != '\0'; i++)
	{
		if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
		{
			l = (s[i] > 'Z') ? 'z' : 'Z';

			d = 13;
			if ((s[i] + d) <= l)
				_putchar(s[i] + d);
			else
			{
				f = (s[i] >= 'a') ? 'a' : 'A';
				_putchar(f + ((d - 1) - (l - s[i])));
			}
			len++;
		}
		else
		{
			_putchar(s[i]);
			len++;
		}
	}
	return (len);
}
