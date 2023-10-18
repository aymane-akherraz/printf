#include "main.h"
/**
 * pt_oct - Prints an octal number
 * @a: the given integer
 * @len: the given length
 *
 * Return: number of digits printed
*/
int pt_oct(va_list a, int len)
{
	unsigned int n = va_arg(a, int);

	if ((n / 8) == 0)
	{
		_putchar('0' + n);
		return (++len);
	}

	len = divide(n, len, 8);
	return (len);
}
