#include "main.h"
void hex_chars(char c);
/**
 * pt_STR - Prints a string including non printable characters
 * @a: the given string
 * @len: the previous length
 *
 * Return: number of digits printed
*/
int pt_STR(va_list a, int len)
{
	char *s = va_arg(a, char *), *ns = "(null)";
	int i;

	if (s != NULL)
	{
		for (i = 0; s[i] != '\0'; i++)
		{
			if ((s[i] > 0 && s[i] < 32) || s[i] >= 127)
			{
				_putchar('\\');
				_putchar('x');
				len += 2;
				if (s[i] < 16)
				{
					_putchar('0');
					len++;
					if (s[i] < 10)
						_putchar('0' + s[i]);
					else
						hex_chars(s[i]);
				}
				else
					len = div_hex(s[i], len, 'X');
			}
			else
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
/**
 * hex_chars - prints the correspending letter for each number
 * @c: the given character
*/
void hex_chars(char c)
{
	switch (c)
	{
	case 10:
		_putchar('A');
		break;
	case 11:
		_putchar('B');
		break;
	case 12:
		_putchar('C');
		break;
	case 13:
		_putchar('D');
		break;
	case 14:
		_putchar('E');
		break;
	case 15:
		_putchar('F');
		break;
	default:
		break;
	}
}
