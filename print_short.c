#include "main.h"
/**
 * pt_s_int - Prints short decimal numbers
 * @a: the given decimal
 * @len: the given length
 *
 * Return: number of digits printed
*/
int pt_s_int(va_list a, int len)
{
	short n;
	short n2 = va_arg(a, int);

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

	len = divide_s(n, len, 10);
	return (len);
}

/**
 * pt_unsigned_short - Prints short unsigned integers
 * @a: the given integer
 * @len: the given length
 *
 * Return: number of digits printed
*/
int pt_unsigned_short(va_list a, int len)
{
	unsigned short n = va_arg(a, unsigned int);

	if ((n / 10) == 0)
	{
		_putchar('0' + n);
		return (++len);
	}

	len = divide_s(n, len, 10);
	return (len);
}

/**
 * pt_s_oct - Prints short octal numbers
 * @a: the given integer
 * @len: the given length
 *
 * Return: number of digits printed
*/
int pt_s_oct(va_list a, int len)
{
	unsigned short n = va_arg(a, unsigned int);

	if ((n / 8) == 0)
	{
		_putchar('0' + n);
		return (++len);
	}

	len = divide_s(n, len, 8);
	return (len);
}
/**
 * pt_s_hex - Prints short hexadecimal numbers
 * @a: the given integer
 * @len: the given length
 * @c: the given case
 *
 * Return: number of digits printed
*/
int pt_s_hex(va_list a, int len, char c)
{
	unsigned short n = va_arg(a, unsigned int);

	if (n < 10)
	{
		_putchar('0' + n);
		return (++len);
	}

	len = div_s_hex(n, len, c);
	return (len);
}
/**
 * div_s_hex - Divides short hexadecimal numbers by 16 until
 * the Quotient equals 0 then print it to the screen
 * @n: the given number
 * @l: the given length
 * @c: the given case (upper or lower)
 * Return: number of digits printed
*/
int div_s_hex(unsigned short n, unsigned int l, char c)
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
		l =	div_s_hex((n / 16), l, c);

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
