#include "main.h"
/**
 * pt_addr - Prints an address
 * @a: the given address
 * @len: the previous length
 *
 * Return: number of digits printed
*/
int pt_addr(va_list a, int len)
{
	int i;
	char *s = "(nil)";
	long p = (long) va_arg(a, void *);

	if (p == 0)
	{
		for (i = 0; s[i] != '\0'; i++)
		{
			_putchar(s[i]);
			len++;
		}
	}
	else
	{
		_putchar('0');
		_putchar('x');
		len += 2;
		len = c_hex(p, len);
	}

	return (len);
}
/**
 * c_hex - Prints hexadecimal number in lowercase
 * @n: the given integer
 * @l: the given length
 *
 * Return: number of digits printed
*/

int c_hex(long n, int l)
{
	unsigned int m = 0;
	int i;

	hex_v t[] = {
		{10, 'a'},
		{11, 'b'},
		{12, 'c'},
		{13, 'd'},
		{14, 'e'},
		{15, 'f'},
		{0, '\0'}
	};

	if ((n / 16) != 0)
		l =	c_hex((n / 16), l);

	m = n % 16;

	if (m < 10)
		_putchar('0' + m);
	else
	{
		for (i = 0; t[i].c != '\0'; i++)
		{
			if (m == t[i].n)
				_putchar(t[i].c);
		}
	}
	l++;
	return (l);
}
