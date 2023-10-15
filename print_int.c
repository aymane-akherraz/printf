#include "main.h"
/**
 * pt_int - Prints an integer
 * @a: the given integer
 * @len: the given length
 *
 * Return: number of digits printed
*/
int pt_int(va_list a, int len)
{
	unsigned int n;
	int n2 = va_arg(a, int);

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

	len = divide(n, len);
	return (len);
}
