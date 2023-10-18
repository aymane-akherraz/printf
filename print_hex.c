#include "main.h"
/**
 * pt_hex - Prints hexadecimal number in lowercase
 * @a: the given integer
 * @len: the given length
 *
 * Return: number of digits printed
*/
int pt_hex(va_list a, int len)
{
	unsigned int n = va_arg(a, int);

	if (n < 10)
	{
		_putchar('0' + n);
		return (++len);
	}

	len = div_hex(n, len, 'x');
	return (len);
}
/**
 * pt_HEX - Prints hexadecimal number in uppercase
 * @a: the given integer
 * @len: the given length
 *
 * Return: number of digits printed
*/
int pt_HEX(va_list a, int len)
{
	unsigned int n = va_arg(a, int);

	if (n < 10)
	{
		_putchar('0' + n);
		return (++len);
	}

	len = div_hex(n, len, 'X');
	return (len);
}
