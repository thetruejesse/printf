#include "main.h"

/**
 * print_hex - prints a num in
 * hexadecimal base lowercase
 * @l: va_list args from _printf
 * @f: pointer to struct flags that
 * dets if a flag is passed to _printf
 * Desc: the func calls convert()
 * which converts input num to
 * correct base and returns a string
 * Return: the number of chars printed
 */
int print_hex(va_list l, flags_t *f)
{
unsigned int num = va_arg(l, unsigned int);
char *str = convert(num, 16, 1);
int count = 0;

if (f->hash == 1 && str[0] != '0')
count += _puts("0x");
count += _puts(str);
return (count);
}

/**
 * print_hex_big - prints a num
 * in hexadec base in uppercase
 * @l: va_list args from _printf
 * @f: pointer to the struct that
 * dets if a flag is passed to _printf
 * if a flag is passed to _printf
 * Desc: func calls convert()
 * which converts the input num in
 * correct base and returns a str
 * Return: the number of chars printed
 */
int print_hex_big(va_list l, flags_t *f)
{
unsigned int num = va_arg(l, unsigned int);
char *str = convert(num, 16, 0);
int count = 0;

if (f->hash == 1 && str[0] != '0')
count += _puts("0X");
count += _puts(str);
return (count);
}

/**
 * print_binary - pritns a num in base 2
 * @l: va_list args from _printf
 * @f: pointer to struct that dets
 * if a flag is passed to _printf
 * Desc: the func calls convert()
 * which converts input num in the
 * corect base and returns a str
 * Return: the num of chars printed
 */
int print_binary(va_list l, flags_t *f)
{
unsigned int num = va_arg(l, unsigned int);
char *str = convert(num, 2, 0);

(void)f;
return (_puts(str));
}

/**
 * print_octal - prints num in base 8
 * @l: va_list args from_printf
 * @f: pointer to struct that dets
 * if a flag is passed to _printf
 * Desc: func calls convert()
 * which in turn converts the input num
 * into correct base and returns a str
 * Return: the num of chars printed
 */
int print_octal(va_list l, flags_t *f)
{
unsigned int num = va_arg(l, unsigned int);
char *str = convert(num, 8, 0);
int count = 0;

if (f->hash == 1 && str[0] != '0')
count += _putchar('0');
	
count += _puts(str);
	
return (count);
}
