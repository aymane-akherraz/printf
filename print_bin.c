#include "main.h"
/**
 * pt_bin - Prints a binary number
 * @a: the given integer
 * @len: the given length
 *
 * Return: number of digits printed
*/
int pt_bin(va_list a, int len)
{
	unsigned int n = va_arg(a, int);

	if ((n / 2) == 0)
	{
		_putchar('0' + n);
		return (++len);
	}

	len = divide(n, len, 2);
	return (len);
}
