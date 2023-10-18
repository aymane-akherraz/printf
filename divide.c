#include "main.h"
/**
 * divide - Divides a number by the given base until the Quotient equals 0
 * then print it to the screen
 * @n: the given number
 * @l: the given length
 * @b: the given base
 * Return: number of digits printed
*/
int divide(unsigned int n, unsigned int l, int b)
{
	if ((n / b) != 0)
		l =	divide((n / b), l, b);

	_putchar('0' + (n % b));
	l++;
	return (l);
}
/**
 * div_hex - Divides a hexadecimal number by 16 until the Quotient equals 0,
 * then print it to the screen
 * @n: the given number
 * @l: the given length
 * @c: the given case (upper or lower)
 * Return: number of digits printed
*/
int div_hex(unsigned int n, unsigned int l, char c)
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
		l =	div_hex((n / 16), l, c);

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
