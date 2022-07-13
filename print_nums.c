#include "main.h"

/**
 * print_int - prints an int
 * @l: va_list of args from _printf
 * @f: pointer to struct flags determining if
 * flag is passed to _printf
 * Return: num of chars printed
 */
int print_int(va_list l, flags_t *f)
{
int n = va_arg(l, int);
int res = count_digit(n);

if (f->space == 1 && f->plus == 0 && n >= 0)
	res += _putchar(' ');
if (f->plus == 1 && n >= 0)
	res += _putchar('+');
	
if (n <= 0)
	res++;
print_number(n);
return (res);
}

/**
 * print_unsigned - prints unsigned int
 * @l: va_list of args from _printf
 * @f: pointer to struct flags determining if a flag
 * is passed to printf
 * Return: number of chars printed
 */
int print_unsigned(va_list l, flags_t *f)
{
unsigned int u = va_arg(l, unsigned int);
char *str = convert(u, 10, 0);

(void)f;
return (_puts(str));
}

/**
 * print_number - helper func that
 * loops though an int and
 * prints all its digits
 * @n: int to be printed
 */
void print_number(int n)
{
unsigned int n1;

if (n < 0)
{
	_putchar('-');
	n1 = -n;
}
else
	n1 = n;
if (n1 / 10)
	print_number(n1 / 10);
_putchar((n1 % 10) + '0');
}

/**
 * count_digit - returns the num of
 * digits in an int for _printf
 * @i: int to evaluate
 * Return: num of digits
 */
int count_digit(int i)
{
unsigned int d = 0;
unsigned int u;

if (i < 0)
	u = i * -1;
else
	u = i;
while (u != 0)
{
	u /= 10;
	d++;
}
return (d);
}
