#include "main.h"
/**
 * pt_l_int - Prints long decimal numbers
 * @a: the given decimal
 * @len: the given length
 *
 * Return: number of digits printed
*/
int pt_l_int(va_list a, int len)
{
	long n;
	long n2 = va_arg(a, long);

	if (n2 < 0)
	{
		_putchar('-');
		n = -n2;
		len++;
	}
	else
		n = n2;

	if ((n / 10) == 0)
	{
		_putchar('0' + n);
		return (++len);
	}

	len = divide_l(n, len, 10);
	return (len);
}

/**
 * pt_unsigned_long - Prints long unsigned integers
 * @a: the given integer
 * @len: the given length
 *
 * Return: number of digits printed
*/
int pt_unsigned_long(va_list a, int len)
{
	unsigned long n = va_arg(a, unsigned long);

	if ((n / 10) == 0)
	{
		_putchar('0' + n);
		return (++len);
	}

	len = divide_l(n, len, 10);
	return (len);
}

/**
 * pt_l_oct - Prints long octal numbers
 * @a: the given integer
 * @len: the given length
 *
 * Return: number of digits printed
*/
int pt_l_oct(va_list a, int len)
{
	unsigned long n = va_arg(a, unsigned long);

	if ((n / 8) == 0)
	{
		_putchar('0' + n);
		return (++len);
	}

	len = divide_l(n, len, 8);
	return (len);
}
/**
 * pt_l_hex - Prints long hexadecimal numbers
 * @a: the given integer
 * @len: the given length
 * @c: the given case
 * Return: number of digits printed
*/
int pt_l_hex(va_list a, int len, char c)
{
	unsigned long n = va_arg(a, unsigned long);

	if (n < 10)
	{
		_putchar('0' + n);
		return (++len);
	}

	len = div_l_hex(n, len, c);
	return (len);
}
/**
 * div_l_hex - Divides long hexadecimal number by 16 until
 * the Quotient equals 0 then print it to the screen
 * @n: the given number
 * @l: the given length
 * @c: the given case (upper or lower)
 * Return: number of digits printed
*/
int div_l_hex(unsigned long n, unsigned int l, char c)
{
	unsigned int m = 0, i;
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
		l =	div_l_hex((n / 16), l, c);

	m = n % 16;

	if (m < 10)
		_putchar('0' + m);
	else
	{
		for (i = 0; t[i].c != '\0'; i++)
		{
			if (m == t[i].n)
			{
				if (c == 'x')
					_putchar(t[i].c);
				else
					_putchar((t[i].c) - 32);
			}
		}
	}
	l++;
	return (l);
}
