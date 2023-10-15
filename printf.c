#include "main.h"
int handle_per(const char *s, int *i, int l, print_f(*p)[], va_list a);
/**
 * _printf - Produces output according to a format
 * @format: a character string
 *
 * Return: the number of characters printed
 * (excluding the null byte used to end output to strings)
*/
int _printf(const char *format, ...)
{
	va_list args;
	int i, j, l = 0, r = 0;

	print_f fts[] = {
		{"c", pt_char},
		{"s", pt_str},
		{"d", pt_dec},
		{"i", pt_int},
		{NULL, NULL}
	};
	print_f(*myPointer)[] = &fts;

	if (format == NULL || (*format == '%' && *(format + 1) == '\0'))
		return (-1);

	va_start(args, format);

	for (i = 0; format[i] != '\0' ; i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			l++;
		}
		for (j = 0; fts[j].fs != NULL; j++)
		{
			if (format[i] == '%')
			{
				if (format[i + 1] == *(fts[j].fs))
				{
					l = fts[j].f(args, l);
					i++;
					break;
				}

				if (fts[j + 1].fs == NULL)
				{
					r = handle_per(format, &i, l, myPointer, args);
					if (r == -1)
						return (-1);
					l = r;
				}
			}
		}
	}
	va_end(args);
	return (l);
}
/**
 * handle_per - handles percentage cases
 * @s: the given format string
 * @i: a pointer to the index i in the previous function
 * @l: the previous length
 * @p: a pointer to fts, the array of structures in _printf
 * @a: an argument pointer variable of type va_list
 *
 * Return: number of characters printed
*/
int handle_per(const char *s, int *i, int l, print_f(*p)[], va_list a)
{
	int j = *i + 1, b = 0;

	while (s[j] != '\0')
	{
		if (s[j] != ' ')
		{
			b = 1;
			break;
		}
		if (s[j + 1] == '\0')
			return (-1);
		j++;
	}
	if (b == 1 && s[j] == 's' && s[j + 1] == '\0')
	{
		l = (*p)[1].f(a, l);
		*i = j;
		return (l);
	}

	if (s[*i + 1] != '\0')
	{
		if (s[*i + 1] == '%')
			(*i)++;

		_putchar(s[*i]);
		l++;
		return (l);
	}
	return (-1);
}
