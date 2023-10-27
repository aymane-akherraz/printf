#ifndef MAIN_H_
#define MAIN_H_

#include <stdlib.h>
#include <stdarg.h>

/**
 * struct print - Struct print
 *
 * @fs: The format specifier
 * @f: The function associated
*/
typedef struct print
{
	char *fs;
	int (*f)(va_list a, int l);
} print_f;

/**
 * struct hex - Struct hex
 *
 * @n: A number
 * @c: The letter associated
*/
typedef struct hex
{
	unsigned int n;
	char c;
} hex_v;

int _putchar(char c);
int divide(unsigned int n, unsigned int l, int b);
int divide_l(unsigned long n, unsigned int l, int b);
int divide_s(unsigned short n, unsigned int l, int b);
int _printf(const char *format, ...);
int pt_char(va_list a, int len);
int pt_str(va_list a, int len);
int pt_dec(va_list a, int len);
int pt_int(va_list a, int len);
int pt_bin(va_list a, int len);
int pt_oct(va_list a, int len);
int div_hex(unsigned int n, unsigned int l, char c);
int pt_l_hex(va_list a, int len, char c);
int pt_s_hex(va_list a, int len, char c);
int div_l_hex(unsigned long n, unsigned int l, char c);
int div_s_hex(unsigned short n, unsigned int l, char c);
int pt_hex(va_list a, int len);
int pt_HEX(va_list a, int len);
int pt_unsigned(va_list a, int len);
int pt_STR(va_list a, int len);
int pt_addr(va_list a, int len);
int c_hex(unsigned long n, int len);
int pt_rev(va_list a, int len);
int pt_rot13(va_list a, int len);
int pt_l_int(va_list a, int len);
int pt_s_int(va_list a, int len);
int pt_unsigned_long(va_list a, int len);
int pt_unsigned_short(va_list a, int len);
int pt_l_oct(va_list a, int len);
int pt_s_oct(va_list a, int len);

#endif
