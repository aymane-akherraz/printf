#include "main.h"

int handle_flags(const char *format, int *i, int l, va_list args);
int handle_per(const char *s, int *i, int l, print_f(*p)[]);
/**
 * _printf - Produces output according to a format
 * @format: a character string
 *
 * Return: the number of characters printed
 * (excluding the null byte used to end output to strings)
*/
int _printf(const char *format, ...)
{
	va_list args, cp;
	int i, j, l = 0, r = 0, b = 0;
	char c;

	print_f fts[] = {
		{"c", pt_char}, {"s", pt_str}, {"d", pt_dec}, {"i", pt_int}, {"b", pt_bin},
		{"o", pt_oct}, {"x", pt_hex}, {"X", pt_HEX}, {"u", pt_unsigned},
		{"S", pt_STR}, {"p", pt_addr}, {"r", pt_rev}, {"R", pt_rot13},
		{NULL, NULL}
	};
	print_f(*myPtr)[] = &fts;
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
				b = 1;
				if (format[i + 1] == '+' || format[i + 1] == ' ' || format[i + 1] == '#')
				{
					va_copy(cp, args);
					l = handle_flags(format, &i, l, cp);
					if (l == -1)
						return (-1);
				}
				if (fts[j + 1].fs == NULL)
				{
					r = handle_per(format, &i, l, myPtr);
					if (r == -1)
						return (-1);
					l = r;
				}
			}
			c = format[i];
			if (c == '%' || (b == 1 && (c == '+' || c == ' ' || c == '#')))
			{
				if (format[i + 1] == *(fts[j].fs))
				{
					l = fts[j].f(args, l);
					i++;
					b = 0;
					break;
				}
			}
		}
	}
	va_end(args);
	va_end(cp);
	return (l);
}
/**
 * handle_flags - Handles flages within the string
 * @format: the given format string
 * @i: a pointer to the index i in the previous function
 * @l: the previous length
 * @args: an argument pointer variable of type va_list
 * Return: the resulted length otherwise -1
*/
int handle_flags(const char *format, int *i, int l, va_list args)
{
	int k = *i + 1, j = *i + 2;
	int n = va_arg(args, int);

	if (format[k] == '+' || format[k] == ' ')
	{
		while (format[j] == ' ')
			j++;
		*i = j - 1;
		if (format[j] == 'd' || format[j] == 'u' || format[j] == 'i')
		{
			if (n >= 0)
			{
				if (format[k] == '+')
					_putchar('+');
				else
					_putchar(' ');
				l++;
			}
		}
		if (format[k] == ' ')
		{
			if (format[j] == '+')
			{
				if (n >= 0)
				{
					_putchar('+');
					l++;
				}
				(*i)++;
			}
			if (format[k + 1] == '%')
			{
				_putchar('%');
				_putchar(format[k + 2]);
				(*i) += 2;
				l += 2;
				return (l);
			}
		}
		if (format[j] == '\0')
			return (-1);
	}
	if (format[k] == '#')
	{
		if (format[j] == 'u' || format[j] == 'i' || format[j] == 'd')
			(*i)++;

		if (format[j] == 'o' || format[j] == 'x' || format[j] == 'X')
		{
			if (n != 0)
			{
				_putchar('0');
				l++;
				if (format[j] == 'x')
				{
					_putchar('x');
					l++;
				}
				if (format[j] == 'X')
				{
					_putchar('X');
					l++;
				}
			}
			(*i)++;
		}
	}
	return (l);
}
/**
 * handle_per - handles percentage within the string
 * @s: the given format string
 * @i: a pointer to the index i in the previous function
 * @l: the previous length
 * @p: a pointer to fts, the array of structures in _printf
 * Return: the resulted length otherwise -1
*/
int handle_per(const char *s, int *i, int l, print_f(*p)[])
{
	int j = *i + 1, k, b = 0;

	while (s[j] == ' ')
		j++;

	if (s[j] != '\0')
	{
		for (k = 0; (*p)[k].fs != NULL; k++)
		{
			if (s[j] == *(*p)[k].fs)
			{
				b = 1;
				break;
			}
		}

		if (s[j] != '%' && b == 0)
		{
			_putchar(s[*i]);
			l++;
		}

		if (s[j] == '%')
		{
			_putchar(s[j]);
			(*i)++;
			l++;
		}
		return (l);
	}
	return (-1);
}
