#include "main.h"
/**
 * pt_unsigned - Prints an unsigned integer
 * @a: the given integer
 * @len: the given length
 *
 * Return: number of digits printed
*/
int pt_unsigned(va_list a, int len)
{
	unsigned int n = va_arg(a, unsigned int);

	if ((n / 10) == 0)
	{
		_putchar('0' + n);
		return (++len);
	}

	len = divide(n, len, 10);
	return (len);
}
